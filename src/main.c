#include "./grid/grid.h"
#include "./algos/mazealgorithms.h"
#include "./debug/debug.h"

#define ROWS 4
#define COLUMNS 4

int main(void)
{
	Cell *grid[ROWS][COLUMNS];

	unsigned int row = 0;
	unsigned int column = 0;

	for (; row < ROWS; ++row)
		for (column = 0; column < COLUMNS; ++column)
			grid[row][column] = create_cell(row, column);

	for (row = 0; row < ROWS; ++row)
	{
		Cell *c;
		for (column = 0; column < COLUMNS; ++column)
		{
			c = grid[row][column];

			unsigned int north_row = row - 1;
			c->coords->north = in_bounds(ROWS, COLUMNS, north_row, column) ? grid[north_row][column] : NULL;

			unsigned int south_row = row + 1;
			c->coords->south = in_bounds(ROWS, COLUMNS, south_row, column) ? grid[south_row][column] : NULL;

			unsigned int east_column = column + 1;
			c->coords->east = in_bounds(ROWS, COLUMNS, row, east_column) ? grid[row][east_column] : NULL;

			unsigned int west_column = column - 1;
			c->coords->west = in_bounds(ROWS, COLUMNS, row, west_column) ? grid[row][west_column] : NULL;
		}
	}

	binary_tree_link(ROWS, COLUMNS, (Cell * (*)[ROWS][COLUMNS]) grid);
	print_maze(ROWS, COLUMNS, grid);
}
