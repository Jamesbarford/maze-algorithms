#include "./grid/grid.h"
#include "./algos/mazealgorithms.h"
#include "./debug/debug.h"

#define ROWS 4
#define COLUMNS 4

int main(void)
{
	Grid *grid = init_grid(ROWS, COLUMNS);

	binary_tree_link(grid);
	print_maze(grid);
	free_grid(grid);
}
