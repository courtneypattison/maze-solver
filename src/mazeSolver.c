/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#include <stdio.h> /* Only for testing */
#include <stdlib.h> 

#include "mazeSolver.h"
#include "stack.h"

struct Stack *solveMaze(int maze[][COLS], struct Dimension mazeDimension,
    struct Stack *solutionPath);

static struct Coordinate findStart(int maze[][COLS],
    struct Dimension mazeDimension);

static void pushAdjacent(int maze[][COLS], struct Dimension mazeDimension,
    struct Stack *solutionPath, struct Coordinate current);

struct Stack *solveMaze(int maze[][COLS], struct Dimension mazeDimension,
    struct Stack *solutionPath)
{
    struct Coordinate start, current;

    start = findStart(maze, mazeDimension);
    push(solutionPath, start);

    do {
        current = peek(solutionPath);
        pushAdjacent(maze, mazeDimension, solutionPath, current);
    } while (maze[current.row][current.col] != FINISH);
    push(solutionPath, current);

    return solutionPath;
}

static struct Coordinate findStart(int maze[][COLS],
    struct Dimension mazeDimension)
{
    int rowNum, colNum;
    struct Coordinate start;

    for (rowNum = 0; rowNum < mazeDimension.height; rowNum++) {
        for (colNum = 0; colNum < mazeDimension.width; colNum++) {
            if (maze[rowNum][colNum] == START) {
                start.row = rowNum;
                start.col = colNum;
                return start;
            }
        }
    }

    fprintf(stderr, "%s:%d There must be a S and F in the provided maze.",
        __FILE__, __LINE__);
    exit(EXIT_FAILURE);
}

static void pushAdjacent(int maze[][COLS], struct Dimension mazeDimension,
    struct Stack *solutionPath, struct Coordinate current)
{
    struct Coordinate up, right, down, left;
    struct Node *popped;

    if (current.row != 0) {
        up.row = current.row - 1;
        up.col = current.col;
        if (maze[up.row][up.col] > WALL) {
            push(solutionPath, up);
            if (maze[up.row][up.col] != FINISH) {
                maze[up.row][up.col] = VISITED;
            }
            return;
        }
    }
    if (current.col != mazeDimension.width - 1) {
        right.row = current.row;
        right.col = current.col + 1;
        if (maze[right.row][right.col] > WALL) {
            push(solutionPath, right);
            if (maze[right.row][right.col] != FINISH) {
                maze[right.row][right.col] = VISITED;
            }
            return;
        }
    }
    if (current.row != mazeDimension.height - 1) {
        down.row = current.row + 1;
        down.col = current.col;
        if (maze[down.row][down.col] > WALL) {
            push(solutionPath, down);
            if (maze[down.row][down.col] != FINISH) {
                maze[down.row][down.col] = VISITED;
            }
            return;
        }
    }
    if (current.col != 0) {
        left.row = current.row;
        left.col = current.col - 1;
        if (maze[left.row][left.col] > WALL) {
            push(solutionPath, left);
            if (maze[left.row][left.col] != FINISH) {
                maze[left.row][left.col] = VISITED;
            }
            return;
        }
    }

    popped = pop(solutionPath);
    free(popped);

    return;
}

