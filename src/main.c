#include <time.h>
#include <stdint.h>

#include "./grid/grid.h"
#include "./algos/mazealgorithms.h"
#include "./debug/debug.h"
#include "./grid/distances.h"

int main(int argc, char **argv)
{
	srand(time(NULL));
	if (argc != 2)
	{
		fprintf(stderr, "Enter dimensions for maze \n");
		exit(1);
		return 1;
	}

	uint32_t dimensions = atoi(argv[1]);

	Grid *grid = init_grid(dimensions, dimensions);

	aldous_broder_link(grid);
	print_maze(grid);
	Distances *distances = calculate_distances(grid);

	printf("Shortest path:\n");
	Distances *shortest_path = find_shortest_path(distances, grid->board[0], get_cell(grid, grid->rows - 1, grid->columns - 1));
	// print_distances(shortest_path);
	print_solution(grid, shortest_path);

	free_grid(grid);
	free_distances(distances);
	free_distances(shortest_path);
	return 0;
}
