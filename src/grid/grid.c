#include "grid.h"

Grid *init_grid(uint32_t rows, uint32_t columns)
{
	Grid *grid = allocate_grid(rows, columns);
	Cell *cell;

	for (uint32_t row = 0; row < rows; ++row)
	{
		for (uint32_t column = 0; column < columns; ++column)
		{
			cell = get_cell(grid, row, column);

			uint32_t north_row = row - 1;
			if (in_bounds(grid, north_row, column))
				set_coord(cell, NORTH, get_cell(grid, north_row, column));

			uint32_t south_row = row + 1;
			if (in_bounds(grid, south_row, column))
				set_coord(cell, SOUTH, get_cell(grid, south_row, column));

			uint32_t east_column = column + 1;
			if (in_bounds(grid, row, east_column))
				set_coord(cell, EAST, get_cell(grid, row, east_column));

			uint32_t west_column = column - 1;
			if (in_bounds(grid, row, west_column))
				set_coord(cell, WEST, get_cell(grid, row, west_column));
		}
	}

	return grid;
}

Cell *get_cell(Grid *grid, uint32_t row, uint32_t column)
{
	return grid->board[row * grid->rows + column];
}

Grid *allocate_grid(uint32_t rows, uint32_t columns)
{
	Grid *grid = (Grid *)malloc(sizeof(Grid) + rows * columns * sizeof(Cell));

	if (grid == NULL)
		fprintf(stderr, "Failed to allocate memory to create grid \n");

	uint32_t count = 0;
	for (uint32_t i = 0; i < rows; ++i)
		for (uint32_t j = 0; j < columns; ++j)
			grid->board[count++] = create_cell(i, j);

	grid->rows = rows;
	grid->columns = columns;
	grid->size = rows * columns;

	return grid;
}

void free_grid(Grid *grid)
{
	free(grid);
}

uint32_t random_row(Grid *grid)
{
	return rand() % grid->rows;
}

uint32_t random_column(Grid *grid)
{
	return rand() % grid->columns;
}

bool in_bounds(Grid *grid, uint32_t row, uint32_t column)
{
	return row < grid->rows && column < grid->columns;
}
