/*
 * Courtney Pattison
 * Last modified: June 10, 2016
 */

#ifndef __MAZE__
#define __MAZE__

#define ROWS 100
#define COLS 100

enum mazeSymbol {
    FLOOR_SYM = ' ',
    START_SYM = 'S',
    FINISH_SYM = 'F'
};

enum mazeComponent {
    START,
    VISITED,
    WALL,
    FLOOR,
    FINISH
};

struct Dimension {
    int width;
    int height;
};

struct Coordinate {
    int row;
    int col;
};

#endif
