#ifndef GRID_H
#define GRID_H

#include <stdint.h>
#include "cell.h"

typedef struct Grid
{
	uint32_t rows;
	uint32_t columns;
	uint32_t size;
	Cell *board[];
} Grid;

Grid *init_grid(uint32_t rows, uint32_t columns);
Grid *allocate_grid(uint32_t rows, uint32_t columns);
Cell *get_cell(Grid *grid, uint32_t row, uint32_t column);

void free_grid(Grid *grid);
bool in_bounds(Grid *grid, uint32_t row, uint32_t column);
uint32_t random_row(Grid *self);
uint32_t random_column(Grid *self);

#endif
