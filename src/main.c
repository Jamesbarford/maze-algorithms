#include <time.h> 
#include "./grid/grid.h"
#include "./algos/mazealgorithms.h"
#include "./debug/debug.h"

#define ROWS 4
#define COLUMNS 4

int main(void)
{
	srand(time(NULL));

	Grid *g = create_grid(ROWS, COLUMNS);
	Cell *grid[g->rows][g->columns];
	unsigned int row = 0;
	unsigned int column = 0;

	for (; row < g->rows; ++row)
		for (column = 0; column < g->columns; ++column)
			grid[row][column] = create_cell(row, column);

	for (row = 0; row < g->rows; ++row)
	{
		Cell *c;
		for (column = 0; column < g->columns; ++column)
		{
			c = grid[row][column];
			c->coords->north = in_bounds(g, row - 1, column) ? grid[row - 1][column] : NULL;
			c->coords->south = in_bounds(g, row + 1, column) ? grid[row + 1][column] : NULL;
			c->coords->east = in_bounds(g, row, column + 1) ? grid[row][column + 1] : NULL;
			c->coords->west = in_bounds(g, row, column - 1) ? grid[row][column - 1] : NULL;
		}
	}

	binary_tree_link(g->rows, g->columns, grid);
	print_maze(g->rows, g->columns, grid);
}
