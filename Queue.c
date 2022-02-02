#include "Queue.h"
//#define constant values
#define TRUE 1
#define FALSE 0

/******
 * In this file, provide all of the definitions of the queue functions as described in Queue.h.
 *
 * ****/

Queue newQueue(){

	Queue q = (Queue) malloc(sizeof(Queue));

	q->head = NULL;
	q->foot = NULL;

	return q;
}

//Free our queue after we free all the nodes
void freeQueue(Queue q){

	if(isEmptyQueue(q) == TRUE)
        free(q);
    else
    {
        while(isEmptyQueue(q) == FALSE){
            struct NodeLL *temp = q->head;
            temp = q->head;
            q->head = q->head -> next;
            free(temp);
        }
        free(q);
    }


}

//Allocating a newNode with a null address
NodeLL *allocateNode(Element value){

	struct NodeLL *newNode;
    newNode = (struct NodeLL*)malloc(sizeof(NodeLL));
    newNode -> element = value;
    newNode -> next = NULL;

    return newNode;

}

//Add our allocated node to the queue
void enqueue(Queue q, Element value){

    if(isEmptyQueue(q) == TRUE)
        q->head = q->foot = allocateNode(value);
    else
    {
        if(q->head -> next == NULL){
            q->head -> next = allocateNode(value)->next;
            }
        q->foot -> next = allocateNode(value);
        q->foot = allocateNode(value);
    }

}

//Remove the head element of the queue then return the element
int dequeue(Queue q, Element *e){
    struct NodeLL *temp;
	if(isEmptyQueue(q) == TRUE)
       return FALSE;
    else
    {
        temp = frontElement(q, e);
        e = temp->element;
        q->head = temp->next;
        free(temp);

        return (int) e;
    }

}

//Get the front element of our queue and return it.
int frontElement(Queue q, Element *e){

	if(isEmptyQueue(q) == TRUE)
        return FALSE;
    else
    {
        e = q->head;

        return e;
    }

}

//Checking if the queue passed in parameter 1 is empty or not and return true or false repectively
int isEmptyQueue(Queue q){

	if(q->head == NULL)
        return TRUE;
    else
    {

        return FALSE;
    }

}

