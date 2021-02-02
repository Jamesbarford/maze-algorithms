#ifndef GRID_H
#define GRID_H
#include "cell.h"

typedef struct Grid
{
	unsigned int rows;
	unsigned int columns;
	unsigned int size;
	struct Cell **board;
} Grid;

Grid *init_grid(unsigned int rows, unsigned int columns);
Grid *allocate_grid(unsigned int rows, unsigned int columns);
void free_grid(Grid *grid);
bool in_bounds(Grid *grid, unsigned int row, unsigned int column);
unsigned int random_row(Grid *self);
unsigned int random_column(Grid *self);

#endif
