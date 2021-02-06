# Maze algorithms

Following along from "Mazes for Programmers: Code Your Own Twisty Little Passages" by "Jamis Buck" in `c`.

Solver an implementation of Dijkstra's algorithm.

## To run:

Compile with:
```
make init
```

To create a maze:
1. Dimensions of the maze `NxN`
```
./maze 10
```

## Outputs

```
Binary tree maze:       Sidewinder maze:        Aldous Broder:
+---+---+---+---+---+   +---+---+---+---+---+   +---+---+---+---+---+
|                   |   |                   |   |   |               |
+   +---+---+   +   +   +   +---+---+---+   +   +   +---+   +---+   +
|   |           |   |   |               |   |   |       |   |       |
+   +   +   +---+   +   +   +---+   +   +   +   +   +   +   +---+   +
|   |   |   |       |   |   |       |   |   |   |   |       |   |   |
+   +---+   +---+   +   +   +   +---+   +   +   +   +   +---+   +   +
|   |       |       |   |   |       |   |   |   |   |   |       |   |
+   +---+---+   +   +   +---+   +---+---+---+   +   +---+   +---+   +
|   |           |   |   |                   |   |   |               |
+---+---+---+---+---+   +---+---+---+---+---+   +---+---+---+---+---+
```
