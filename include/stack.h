/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#ifndef __STACK__
#define __STACK__

#include "list.h"

struct Stack {
    struct Node *list;
    struct Node *top; 
    int size;
};

/* 
 * PreConditions: none
 * PostConditions: A stack is created and initialized to empty
 */
struct Stack *createStack();


/* 
 * PreConditions: An initialized stack exists
 * PostConditions: The stack is destroyed and all associated memory is freed
 */
void destroyStack(struct Stack *stack);

/* 
 * PreConditions: The stack is not full
 * PostConditions: An element is added to the stack, the length is increased by
 * one, the top of the stack points to the newly added element
 */
void push(struct Stack *stack, struct Coordinate coordinate);

/* 
 * PreConditions: The stack is not empty
 * PostConditions: The first (top) element of the stack is removed and returned
 * to the caller. The top of the stack is set to the successor of the removed
 * element, the length of the stack is decremented by one.
 */
struct Node *pop(struct Stack *stack);

/* 
 * PreConditions: The stack is not empty
 * PostConditions: Returns the element that is at the top of the stack but does
 * not remove that element from the stack
 */
struct Coordinate peek(struct Stack *stack);

#endif
