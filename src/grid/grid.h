#ifndef GRID_H
#define GRID_H
#include "cell.h"

typedef struct RandomCoords {
	unsigned int row;
	unsigned int column;
} RandomCoords;

typedef struct Grid
{
	unsigned int rows;
	unsigned int columns;
	unsigned int size;
} Grid;

Grid *create_grid(unsigned int rows, unsigned int columns);
RandomCoords *get_random_coords(Grid *grid);
bool in_bounds(Grid *self, unsigned int row, unsigned int column);

#endif
