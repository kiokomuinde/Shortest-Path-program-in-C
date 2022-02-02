#include <stdlib.h>
#include <stdio.h> 
#include "Graph.h"
#define TRUE 1
#define FALSE 0

/******
 * In this file, provide all of the definitions of the graph functions as described in Graph.h.
 *
 * ****/

//Create a new graph and initialize its members
Graph newGraph(int n){
	Graph g = malloc(sizeof(Graph));
	
	//If grapgh couldnt be created exit the program
	if (!g){
		printf("Unable to create to create a graph\n");
		exit(EXIT_FAILURE);
	}

	//Malloc our adjacency matrix and initialize n
	g->adjacencyM = (Vertex **)malloc(n*sizeof(Vertex *));
	g->n = n;

	for (int i=0; i<n; i++)
		//Using Usingt calloc to initialize array members to 0
         g->adjacencyM[i] = (Vertex*)calloc(n,sizeof(Vertex));

     return g;

}

//Free our graph after freeing the adjacency matrix
void freeGraph(Graph g){
	if(g->adjacencyM)
		free(g->adjacencyM);

	if(g)
		free(g);
}


//Adding our edges into our matrix
void addEdge(Graph g, Edge e){

	g->adjacencyM[e.fromVertex][e.toVertex] = e.toVertex; 
    

}

//Get the first vertext from our start vertex
Edge firstAdjacent(Graph g, Vertex v){

	Edge e;

	for (int i = 0; i < g->n; ++i)
	{
		if(g->adjacencyM[v][i] != 0){
		e.fromVertex = v;
		e.toVertex = g->adjacencyM[v][i];
		return e;
	}
	}
	//Equating edge to null if there is no edge similar to e
	e.fromVertex = 0;
	e.toVertex = 0;

	//Returning a null edge
	return e;

}

//Get the next vertex from the toVertex of the current edge
Edge nextAdjacent(Graph g, Edge e){

	
	if(g->adjacencyM[e.fromVertex][e.toVertex] != 0){
		return e;
	}
		
	//Equating edge to null if there is no edge similar to e
	e.fromVertex = 0;
	e.toVertex = 0;

	//Returning a null edge
	return e;
}

//Function definition of our BFS
int breadthFirstSearch(Graph g, Vertex start, Vertex destination, int pred[]){

	//Variable declaration and definition for our queue, element and a temporary array
	Queue q1 = newQueue();
	Element *e;
	for (int i = 0; i < g->n; i++){ 
        pred[i] = -1; 
    }


    //Destination cant be 0
    if (destination == 0)
     {
     	return FALSE;
     } 


    //Enqueue our starting vertex
	enqueue(q1, start);
	Edge ed;

	//Loop through the queue till we get the destination if not return NULL
	while (isEmptyQueue(q1) == FALSE) {
	int temp = 0; 
        
        //Loop through our adjacency matrix
        for (int i = 0; i < g->n; i++) { 

        	//Get the top element of the queue then remove it from the queue
        	int u = dequeue(q1, e);
            int j = 0;

            //Loop through the inner most dimension of the adjuacency array i.e 2  
            while (j < g->n){
            	if (j == 0 && i == 0)
            	{
            		//Get the first vertex from start vertex
            		temp = firstAdjacent(g, start).toVertex;
            		if(temp != 0)
	            	{
	            		
	                	if (pred[temp] == -1)
	            		{
	            			pred[temp] = u;
	            		}
	                	enqueue(q1, temp);
	            	}
            	}else{

            		//Get the next edges to the current one
            		ed.fromVertex = u;

            		ed.toVertex = j;

            		if (nextAdjacent(g, ed).toVertex != 0)
	            	{
	            		temp = nextAdjacent(g, ed).toVertex;
	            		if (pred[temp] == -1)
	            		{
	            			pred[temp] = u;
	            			
	            		}

	            		enqueue(q1, temp);
	                	
	                	
	            	}
            	}

            	j++;
                // We stop BFS when we find  
    			if (temp == destination){
    				//Free our queue after use
    				free(q1);
                	return TRUE;
    
    			}

    			//Return false if the start does not exist in our graph
    			if (temp == 0 && j == 15)
    			{
    				free(q1);
    				return FALSE;
    			}
                    
    		} 
    	}
    } 

    //Free our queue after use
    free(q1);	
  	
  	//Return False if destination  does not exist
    return FALSE; 

}

void shortestPath(Graph g, Vertex start, Vertex destination){
	int pred[g->n];

	//If the path is not available in our graph return
	if(breadthFirstSearch(g, start, destination, pred) == FALSE){

		printf("There is no path from %d to %d.\n", start, destination);
		return;
	}

	//Declare our stack and push our destination to stack
	Stack st;
    st = newStack(g->n);
    int crawl = destination;
    push(st, crawl);  
    while (pred[crawl] != -1) {  
        crawl = pred[crawl];
        push(st, crawl);
        if (crawl == start)
        {
        	break;
        }
    } 

    printf("Shortest path from %d to %d: ", start, destination);

    int k = 0;

    //Print the top most element of our stack then pop it
    while(!isEmptyStack(st)){

        if (k > 0)
        {
            printf("->");
        }
        k++;
        printf("%d", (int) topElement(st));
        pop(st);
    }

    //Free our stack after use
    free(st);

    printf("\n");	
}


	

