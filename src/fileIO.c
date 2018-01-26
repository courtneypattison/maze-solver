/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileIO.h"

struct Dimension accessMazeFile(const char *filename, int maze[][COLS],
    int mazeRaw[][COLS]);

static struct Dimension readMazeFile(FILE *mazeFile, int maze[][COLS],
    int mazeRaw[][COLS]);

void printMazeSolution(int mazeRaw[][COLS], struct Dimension mazeDimension,
    struct Stack *solutionPath);

struct Dimension accessMazeFile(const char *filename, int maze[][COLS],
    int mazeRaw[][COLS])
{
    FILE *mazeFile;
    struct Dimension mazeDimension;

    mazeFile = fopen(filename, "r");
    if (mazeFile == NULL) {
        fprintf(stderr, "Sorry, %s cannot be accessed.\n", filename);
        fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, strerror(errno));
        exit(EXIT_FAILURE);
    }

    mazeDimension = readMazeFile(mazeFile, maze, mazeRaw);

    fclose(mazeFile);

    return mazeDimension;
}

static struct Dimension readMazeFile(FILE *mazeFile, int maze[][COLS],
    int mazeRaw[][COLS])
{
    int character;
    int rowNum, colNum;
    struct Dimension mazeDimension;

    rowNum = colNum = 0;
    while ((character = fgetc(mazeFile)) != EOF) {
        if (character == '\n') {
            rowNum++;
            mazeDimension.height = rowNum;
            colNum = 0;
        } else {
            mazeRaw[rowNum][colNum] = character;
            switch (character) {
            case START_SYM:
                maze[rowNum][colNum] = START;
                break;
            case FINISH_SYM:
                maze[rowNum][colNum] = FINISH;
                break;
            case FLOOR_SYM:
                maze[rowNum][colNum] = FLOOR;
                break;
            default:
                maze[rowNum][colNum] = WALL;
                break;
            }
            colNum++;
            mazeDimension.width = colNum;
        }
    }

    return mazeDimension;
}

void printMazeSolution(int mazeRaw[][COLS], struct Dimension mazeDimension,
    struct Stack *solutionPath)
{
    int i, j, k;
    int solutionPathLength;
    struct Node *popped;

    solutionPathLength = solutionPath->size;

    for (k = 0; k < solutionPathLength; k++) {
        popped = pop(solutionPath);
        for (i = 0; i < mazeDimension.height; i++) {
            for (j = 0; j < mazeDimension.width; j++) {
                if (popped->coordinate.row == i && popped->coordinate.col == j) {
                    free(popped);
                    mazeRaw[i][j] = '#';
                }
            }
        }
    }

    for (i = 0; i < mazeDimension.height; i++) {
        for (j = 0; j < mazeDimension.width; j++) {
            printf("%c", mazeRaw[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return;
}
