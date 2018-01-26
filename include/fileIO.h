/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#ifndef __FILEIO__
#define __FILEIO__

#include "maze.h"
#include "stack.h"

/*
 * Preconditions: A maze less than or equal to 100 x 100 characters
 * Postconditions: The maze's dimensions are returned
 */
struct Dimension accessMazeFile(const char *filename, int maze[][COLS],
    int mazeRaw[][COLS]);

/*
 * Preconditions: A maze less than or equal to 100 x 100 characters and a
 * stack storing the solution path for that maze
 * Postconditions: The maze with the solution path is printed to stdout
 */
void printMazeSolution(int mazeRaw[][COLS], struct Dimension mazeDimension,
    struct Stack *solutionPath);

#endif
