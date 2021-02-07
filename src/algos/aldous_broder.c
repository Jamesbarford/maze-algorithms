#include "mazealgorithms.h"

void aldous_broder_link(Grid *g)
{
	uint32_t start_row = random_row(g);
	uint32_t start_column = random_column(g);
	uint32_t unvisited = g->size - 1;

	Cell *cell = get_cell(g, start_row, start_column);
	Cell *neighbour = NULL;

	while (unvisited > 0)
	{
		short random_direction = rand() % 4;
		if (!has_coord(cell, random_direction))
			continue;

		neighbour = get_neighbour(cell, random_direction);

		if (unlinked_cell(neighbour))
		{
			add_cell_link(cell, random_direction, neighbour, true);
			unvisited--;
		}
		cell = neighbour;
	}
}
