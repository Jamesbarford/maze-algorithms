#include "grid.h"

Grid *init_grid(unsigned int rows, unsigned int columns)
{
	Grid *grid = allocate_grid(rows, columns);
	Cell *cell;

	for (int row = 0; row < rows; ++row)
	{
		for (int column = 0; column < columns; ++column)
		{
			cell = &grid->board[row][column];

			int north_row = row - 1;
			cell->coords->north = in_bounds(grid, north_row, column) ? &grid->board[north_row][column] : NULL;

			int south_row = row + 1;
			cell->coords->south = in_bounds(grid, south_row, column) ? &grid->board[south_row][column] : NULL;

			int east_column = column + 1;
			cell->coords->east = in_bounds(grid, row, east_column) ? &grid->board[row][east_column] : NULL;

			int west_column = column - 1;
			cell->coords->west = in_bounds(grid, row, west_column) ? &grid->board[row][west_column] : NULL;
		}
	}

	return grid;
}

Grid *allocate_grid(unsigned int rows, unsigned int columns)
{
	Grid *grid = malloc(sizeof(*grid));
	Cell *cell_values = (Cell *)calloc(rows * columns, sizeof(Cell));
	Cell **board = (Cell **)malloc(rows * sizeof(Cell *));

	if (grid == NULL)
		fprintf(stderr, "Failed to allocate memory to create grid \n");

	if (cell_values == NULL)
		fprintf(stderr, "Failed to allocate memory for cells \n");

	if (board == NULL)
		fprintf(stderr, "Failed to allocate memory for rows \n");

	for (int i = 0; i < rows; ++i)
		board[i] = cell_values + i * rows;

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			board[i][j] = *create_cell(i, j);

	grid->board = board;
	grid->rows = rows;
	grid->columns = columns;
	grid->size = rows * columns;

	return grid;
}

void free_grid(Grid *grid)
{
	free(*grid->board);
	free(grid->board);
	free(grid);
}

unsigned int random_row(Grid *grid)
{
	return rand() % grid->rows;
}

unsigned int random_column(Grid *grid)
{
	return rand() % grid->columns;
}

bool in_bounds(Grid *grid, unsigned int row, unsigned int column)
{
	return row < grid->rows && column < grid->columns;
}
