/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#include <stdio.h>
#include <stdlib.h>

#include "fileIO.h"
#include "maze.h"
#include "mazeSolver.h"
#include "stack.h"

int main(int argc, char *argv[])
{
    int maze[ROWS][COLS];
    int mazeRaw[ROWS][COLS];
    struct Dimension mazeDimension;
    struct Stack *solutionPath;

    if (argc != 2) {
        fprintf(stderr, "%s:%d Enter the filename when running the program: "
            "./bin/A1 <maze.txt>\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    solutionPath = createStack();
    mazeDimension = accessMazeFile(argv[1], maze, mazeRaw);
    solutionPath = solveMaze(maze, mazeDimension, solutionPath);
    printMazeSolution(mazeRaw, mazeDimension, solutionPath);
    destroyStack(solutionPath);

    return 0;
}
