
#include "Maze.h"

int main() {
    setbuf(stdout,NULL);
    Maze maze;
    MazeInit(&maze);
    MazePath(maze);

    return 0;
}/* size of maze, entry pos, exit pos
10 12
1 1
7 11
0 0 0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 0 1 1 1 0
0 1 0 1 0 1 1 1 1 0 1 0
0 1 1 1 1 1 0 0 1 1 1 0
0 1 1 0 1 1 1 1 1 0 1 0
0 0 1 0 1 0 1 0 0 1 1 0
0 1 1 1 1 1 0 1 1 1 0 0
0 1 0 1 0 1 1 0 1 0 1 1
0 1 1 1 1 0 1 0 1 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0

 */

