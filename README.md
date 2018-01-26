# Maze solver
A stack based maze solver.

## Compilation
make

## Usage
./bin/A1 docs/mazes/maze.txt
./bin/testStackA1
./bin/testMazeSolverA1

## Testing
See testing documentation in docs/

## Sample output
```
$ ./bin/A1 docs/mazes/maze.txt
+-+-+-+-+-+-+-+-+-+-+
####|#######| |   | |
+-+#+#+-+-+#+ + + + +
| |#|###|###|   |   |
+ +#+-+#+#+-+ + +-+-+
|  #####|###| | |   |
+ +-+-+-+-+#+ +-+ + +
| |      ###|   | | |
+-+ +-+-+#+-+-+ + + +
|   |#####| |   | | |
+ +-+#+-+-+ + + + +-+
|   |#####    | |   |
+-+ +-+-+#+ +-+ +-+ +
| | |#####| |   |   |
+ + +#+-+-+-+ +-+ +-+
|   |#|   |   |   | |
+-+-+#+ + + +-+ +-+ +
| |  #| | |     |###|
+ + +#+-+ +-+-+-+#+#+
|   |#############|##
+-+-+-+-+-+-+-+-+-+-+
```

## Known limitations
- level file must be correctly formatted according to assignment specifications
- program will exit with limited information when input is invalid
- stack only stores struct Coordinate

## References
- http://courses.cs.washington.edu/courses/cse373/02wi/slides/BinSortEtc/sld023.htm
- http://stackoverflow.com/questions/16121593/logic-behind-a-stack-based-maze-algorithm
- https://www.packtpub.com/books/content/simple-pathfinding-algorithm-maze
- https://www.youtube.com/watch?v=qt6oMBKRxEU

