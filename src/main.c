#include "./grid/grid.h"
#include "./algos/mazealgorithms.h"
#include "./debug/debug.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Enter dimensions for maze \n");
		exit(1);
		return 1;
	}

	unsigned int dimensions = atoi(argv[1]);

	Grid *grid = init_grid(dimensions, dimensions);

	binary_tree_link(grid);
	print_maze(grid);
	free_grid(grid);

	return 0;
}
