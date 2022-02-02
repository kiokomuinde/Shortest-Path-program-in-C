#include "Graph.h" 
#define MAX_LINE_LENGTH 50
int main(int argc, char *argv[]) 
{ 

    //Checking for input arguments and validation
    if( argc == 1 || argc > 2) {
      printf("ERROR: Missing commandline input for the input file\n");
      exit(EXIT_FAILURE);
    }

     //Declaring and defining the file pointer
    FILE *inputFile;
    inputFile = fopen(argv[1], "r");
    if(inputFile == NULL){

        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    //Variable declaration to be used later in the File maniplation
    char ch[MAX_LINE_LENGTH], temp[20];
    int numVerts = 0, directedEdges = 0, numPaths = 0;
    int iterator = 0, n = 0, start = 0, destination = 0;
    Edge e;
    Graph g;
    int y = 0;

    //Loop through our file to get its contents
    while((fgets(ch, MAX_LINE_LENGTH, inputFile)) != NULL){

        if (iterator == 0)
        {
            sscanf(ch,"%d", &numVerts);
        }else if(iterator == 1){
            sscanf(ch,"%d", &directedEdges);
            //Initialize our grapgh and n
            n = directedEdges; 
            g = newGraph(n);
        }else if(iterator > 1 && iterator < directedEdges + 2){
            y++;
            sscanf(ch,"%d %d", &e.fromVertex, &e.toVertex);
            //Add a new edge to our matrix
            addEdge(g, e);
        }else if( iterator == directedEdges + 2){
            sscanf(ch,"%d", &numPaths);
        }else if(iterator > directedEdges + 2 && iterator < directedEdges + 7 ){

            //Print the numPaths shortest paths
            sscanf(ch,"%s %d %d",&temp, &start, &destination);
            shortestPath(g, start, destination);
        }

        iterator++;
    }

    freeGraph(g);
    fclose(inputFile);
    return 0; 
} 


