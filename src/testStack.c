/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "math.h"
#include "stack.h"

void printTest(int boolean);

int main(void)
{
    struct Stack *stack;
    struct Coordinate testPush, testPeek;
    struct Node *testPop;
    int i;

    printf("Stack Testing\n"
           "=============\n");

    printf("\ncreateStack()\n"
             "-------------\n");
    stack = createStack();
    /* Uncommenting commented code will result in expected stack error messages*/
    /* printList(stack->list); */
    printTest(stack->top == NULL);
    printf("stack->top\texpected: NULL, actual: %p\n", (void *)stack->top);
    printTest(stack->size == 0);
    printf("stack->size\texpected: 0, actual: %d\n", stack->size);

    printf("\npush()\n"
             "------\n");
    for (i = 0; i > -3; i--) {
        testPush.row = i;
        push(stack, testPush);
        testPeek = peek(stack);
        printTest(testPush.row == testPeek.row);
        printf("testPush.row\texpected: %d, actual: %d\n", i, testPeek.row);
    }

    printf("\npop()\n"
             "-----\n");
    for (i = -3; i < 0; i++) {
        testPeek = peek(stack);
        testPop = pop(stack);
        printTest(testPop->coordinate.row == testPeek.row);
        printf("testPop->coordinate.row\texpected: %d, actual: %d\n",
            i + 1, testPop->coordinate.row);
        free(testPop);

        /* testPeek = peek(stack); */
        /* printTest(stack->top->coordinate.row == testPeek.row); */
        /* printf("stack->top->coordinate.row\texpected: %d, actual: %d\n", */
        /*     i + 1, testPop->coordinate.row); */

        printTest(stack->size == abs(i + 1));
        printf("stack->size\t\texpected: %d, actual: %d\n",
            abs(i + 1), stack->size);
    }

    printf("\npeek()\n"
             "------\n");
    for (i = 10000; i < 1000000000; i *= 100) {
        testPush.row = i;
        push(stack, testPush);
        testPeek = peek(stack);
        printTest(testPeek.row == testPush.row);
        printf("testPeek.row\texpected: %d, actual: %d\n", i, testPeek.row);
    }

    printf("\ndestroyStack()\n"
             "--------------\n");
    destroyStack(stack);

    return 0;
}

void printTest(int boolean) {
    if (boolean == 1) {
        printf("PASS\t");
    } else {
        printf("FAIL\t");
    }

    return;
}
