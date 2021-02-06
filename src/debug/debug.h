#ifndef DEBUG_H
#define DEBUG_H

#include <string.h>
#include "../grid/grid.h"
#include "../grid/distances.h"

void print_maze(Grid *g);
void print_solution(Grid *g, Distances *shortest_path);

#endif
