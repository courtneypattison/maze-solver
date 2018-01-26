/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#ifndef __LIST__
#define __LIST__

#include "maze.h"

struct Node {
	struct Coordinate coordinate;
	struct Node *next;
};

/*
 * Preconditions: none
 * Postconditions: a new list is created and is empty
 */
struct Node *createList();

/*
 * Preconditions: none
 * Postconditions: a new node is created and populated with an integer
 */
struct Node *initNode(struct Coordinate coordinate);

/*
 * Preconditions: a list exists
 * Postconditions: the element is added to the front of the list and the length
 * of the list is increased by one
 */
struct Node *addFront(struct Node *head, struct Coordinate coordinate);

/*
 * Preconditions: a non-empty list is available
 * Postconditions: the first element in the list is returned
 */
struct Node *getFront(struct Node *head);

/*
 * Preconditions: a non-empty list is available
 * Postconditions: the first element of the list is removed, the length of the
 * list is decreased by one, and the removed element is returned
 */
struct Node *deleteFront(struct Node *head);

/*
 * Preconditions: a list exists
 * Postconditions: the length of the list is returned
 */
int getLength(struct Node *head);

/*
 * Preconditions: a list exists
 * Postconditions: the list elements are printed separated by spaces
 */
void printList(struct Node *head);

/*
 * Preconditions: a list exists
 * Postconditions: the list is destroyed
 */
void destroyList();

#endif
