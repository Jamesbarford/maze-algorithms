#include "grid.h"

Grid *create_grid(int unsigned rows, unsigned int columns)
{
	Grid *grid = malloc(sizeof(*grid));
	if (grid == NULL)
		fprintf(stderr, "Failed to allocate memory to create grid \n");

	grid->rows = rows;
	grid->columns = columns;
	grid->size = rows * columns;

	return grid;
}

unsigned int random_row(Grid *self)
{
	return rand() % self->rows;
}

unsigned int random_column(Grid *self)
{
	return rand() % self->columns;
}

bool in_bounds(Grid *self, unsigned int row, unsigned int column)
{
	return row <= self->rows && column <= self->columns;
}
