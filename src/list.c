/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static void exitIfNull(struct Node *node)
{
    if (node == NULL) {
        fprintf(stderr, "%s:%d Null pointer", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
}

struct Node *createList()
{
    struct Node *dummyNode;

    dummyNode = malloc(sizeof *dummyNode);
    exitIfNull(dummyNode);

	dummyNode->next = NULL;

	return dummyNode;
}

struct Node *initNode(struct Coordinate coordinate)
{
    struct Node *newNode;

    newNode = malloc(sizeof *newNode);
    exitIfNull(newNode);

	newNode->coordinate = coordinate;
	newNode->next = NULL;

	return newNode;
}

struct Node *addFront(struct Node *head, struct Coordinate coordinate)
{
    struct Node *frontNode;

    exitIfNull(head);

    frontNode = initNode(coordinate);
    frontNode->next = head->next;
    head->next = frontNode;

    return frontNode;
}

struct Node *getFront(struct Node *head)
{
    struct Node *front;

    exitIfNull(head);

    front = head->next;

    return front;
}

struct Node *deleteFront(struct Node *head)
{
    struct Node *front;

    exitIfNull(head);

    front = getFront(head);
    head->next = front->next;

    return front;
}

int getLength(struct Node *head)
{
    int length;
    struct Node *current;

    exitIfNull(head);

    length = 0;
    current = head->next;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

void printList(struct Node *head)
{
    struct Node *current;

    exitIfNull(head);

    current = head->next;
    while (current != NULL) {
        printf("(%d, %d)\n", current->coordinate.row, current->coordinate.col);
        current = current->next;
    }
    printf("\n");

    return;
}

void destroyList(struct Node *head)
{
    struct Node *current, *front;

    exitIfNull(head);

    current = head->next;
    while (current != NULL) {
        front = deleteFront(head);
        current = current->next;
        free(front);
    }
    free(head);

    return;
}

