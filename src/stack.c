/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct Stack *createStack()
{
    struct Stack *stack;

    stack = malloc(sizeof *stack);
    if (stack == NULL) {
        fprintf(stderr, "%s:%d Null pointer", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    stack->list = createList();
    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void destroyStack(struct Stack *stack)
{
    destroyList(stack->list);
    free(stack);

    return;
}

void push(struct Stack *stack, struct Coordinate coordinate)
{
    stack->top = addFront(stack->list, coordinate);
    stack->size++;

    return;
}

struct Node *pop(struct Stack *stack)
{
    struct Node *popped;

    if (stack->size > 0) {
        popped = deleteFront(stack->list);
        stack->top = getFront(stack->list);
        stack->size--;
        return popped;
    } else {
        destroyStack(stack);
        fprintf(stderr, "You can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }
}

struct Coordinate peek(struct Stack *stack)
{
    if (stack->size > 0) {
        return stack->top->coordinate;
    } else {
        destroyStack(stack);
        fprintf(stderr, "You can't peek at an empty stack\n");
        exit(EXIT_FAILURE);
    }
}
