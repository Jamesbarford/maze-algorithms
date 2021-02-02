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

Grid *create_grid(unsigned int rows, unsigned int columns);
bool in_bounds(unsigned int MAX_ROW, unsigned int MAX_COL, unsigned int row, unsigned int column);
unsigned int random_row(Grid *self);
unsigned int random_column(Grid *self);

#endif
