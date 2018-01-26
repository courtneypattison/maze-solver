/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#ifndef __MAZESOLVER__
#define __MAZESOLVER__

#include "maze.h"

/*
 * Preconditions: A parsed maze less than or equal to 100 x 100 characters and
 * an initialized stack for the solution path
 * Postconditions: A stack that holds the solution path is returned
 */
struct Stack *solveMaze(int maze[][COLS], struct Dimension mazeDimension,
    struct Stack *solutionPath);

#endif
