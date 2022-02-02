#include "Stack.h"

/******
 * In this file, provide all of the definitions of the stack functions as described in stack.h.
 *
 * ****/
 

/******
 * In this file, provide all of the definitions of the stack functions as described in stack.h.
 *
 * ****/


Stack newStack(int maxSize){

	// Initializing the array of stacks with malloc.
	Stack s =  malloc(sizeof(Stack)); 

	if (!s) return 0;

	s->count = -1; 
	s->maxSize = maxSize; 

	//mallocing the stackElements array.
	s->stackElements = (int*) malloc(maxSize * sizeof(int)); 

	if (!s->stackElements) return 0;

	return s;

}

//Free stack to free both StackImp and stackElements arrays.
void freeStack(Stack s){

	free(s->stackElements);
	free(s);

}


//push an ele4ment to stack.
void push(Stack s, Element e){

	s->stackElements[++s->count] = e;

}


//Pop an element from stack.
Element pop(Stack s){

	if (!isEmptyStack(s)) 
		return s->stackElements[s->count--] ; 


}

//Check if stack is empty 
int isEmptyStack(Stack s){

	return s->count == -1;


}


// Return the top element in the stack.
Element topElement(Stack s){

	return s->stackElements[s->count];

}