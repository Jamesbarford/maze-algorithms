#include "./grid/grid.h"
#include "./algos/mazealgorithms.h"
#include "./debug/debug.h"

#define ROWS 4
#define COLUMNS 4

int main(void)
{
	// Cell *grid[ROWS][COLUMNS];
	unsigned int row = 0;
	unsigned int column = 0;

	Grid *g = create_grid(ROWS, COLUMNS);

	for (row = 0; row < ROWS; ++row)
	{
		Cell c;
		for (column = 0; column < COLUMNS; ++column)
		{
			c = g->board[row][column];

			int north_row = row - 1;
			c.coords->north = in_bounds(ROWS, COLUMNS, north_row, column) ? &g->board[north_row][column] : NULL;

			int south_row = row + 1;
			c.coords->south = in_bounds(ROWS, COLUMNS, south_row, column) ? &g->board[south_row][column] : NULL;

			int east_column = column + 1;
			c.coords->east = in_bounds(ROWS, COLUMNS, row, east_column) ? &g->board[row][east_column] : NULL;

			int west_column = column - 1;
			c.coords->west = in_bounds(ROWS, COLUMNS, row, west_column) ? &g->board[row][west_column] : NULL;
		}
	}

	binary_tree_link(g);
	print_maze(g);
}
