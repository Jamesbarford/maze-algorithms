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

RandomCoords *get_random_coords(Grid *grid)
{
	RandomCoords *random_coords = malloc(sizeof(*random_coords));
	if (grid == NULL)
		fprintf(stderr, "Failed to allocate memory for random coords \n");

	random_coords->row = rand() % grid->rows;
	random_coords->column = rand() % grid->columns;

	return random_coords;
}

bool in_bounds(Grid *self, unsigned int row, unsigned int column)
{
	return row <= self->rows && column <= self->columns;
}
