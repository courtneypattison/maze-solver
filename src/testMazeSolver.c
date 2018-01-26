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

int main(void)
{
    int maze[ROWS][COLS];
    int mazeRaw[ROWS][COLS];
    struct Dimension mazeDimension;
    struct Stack *solutionPath;

    printf("Maze Solver Testing\n"
           "===================\n");

    printf("\n\nMaze\n");
    solutionPath = createStack();
    mazeDimension = accessMazeFile("docs/mazes/maze.txt", maze, mazeRaw);
    solutionPath = solveMaze(maze, mazeDimension, solutionPath);
    printMazeSolution(mazeRaw, mazeDimension, solutionPath);
    destroyStack(solutionPath);

    printf("\n\nExtremely simple maze\n");
    solutionPath = createStack();
    mazeDimension = accessMazeFile("docs/mazes/mazeEvenSimpler.txt", maze, mazeRaw);
    solutionPath = solveMaze(maze, mazeDimension, solutionPath);
    printMazeSolution(mazeRaw, mazeDimension, solutionPath);
    destroyStack(solutionPath);

    /* printf("\n\nMaze that exceeds the maze width restrictions\n"); */
    /* solutionPath = createStack(); */
    /* mazeDimension = accessMazeFile("docs/mazes/mazeGreaterThan100.txt", maze, mazeRaw); */
    /* solutionPath = solveMaze(maze, mazeDimension, solutionPath); */
    /* printMazeSolution(mazeRaw, mazeDimension, solutionPath); */
    /* destroyStack(solutionPath); */

    printf("\n\nMaze with the maximum dimensions\n");
    solutionPath = createStack();
    mazeDimension = accessMazeFile("docs/mazes/mazeMaxSize.txt", maze, mazeRaw);
    solutionPath = solveMaze(maze, mazeDimension, solutionPath);
    printMazeSolution(mazeRaw, mazeDimension, solutionPath);
    destroyStack(solutionPath);

    printf("\n\nMaze without halls\n");
    solutionPath = createStack();
    mazeDimension = accessMazeFile("docs/mazes/mazeNoHalls.txt", maze, mazeRaw);
    solutionPath = solveMaze(maze, mazeDimension, solutionPath);
    printMazeSolution(mazeRaw, mazeDimension, solutionPath);
    destroyStack(solutionPath);

    printf("\n\nSimple maze\n");
    solutionPath = createStack();
    mazeDimension = accessMazeFile("docs/mazes/mazeSimple.txt", maze, mazeRaw);
    solutionPath = solveMaze(maze, mazeDimension, solutionPath);
    printMazeSolution(mazeRaw, mazeDimension, solutionPath);
    destroyStack(solutionPath);

    printf("\n\nMaze with wide halls\n");
    solutionPath = createStack();
    mazeDimension = accessMazeFile("docs/mazes/mazeWideHalls.txt", maze, mazeRaw);
    solutionPath = solveMaze(maze, mazeDimension, solutionPath);
    printMazeSolution(mazeRaw, mazeDimension, solutionPath);
    destroyStack(solutionPath);

    return 0;
}
