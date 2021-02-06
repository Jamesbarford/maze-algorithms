#include "mazealgorithms.h"

void side_winder_link(Grid *g)
{
	for (unsigned int row = 0; row < g->rows; ++row)
	{
		Cell *run[g->columns];
		Cell *cell;
		int ptr = 0;
		for (unsigned int column = 0; column < g->columns; ++column)
		{
			cell = get_cell(g, row, column);
			run[ptr++] = cell;

			bool at_east = !has_coord(cell, EAST);
			bool at_north = !has_coord(cell, NORTH);
			bool close_run = at_east || (!at_north && (rand() % 2) == 0);

			if (close_run)
			{
				int idx = rand() % ptr;
				Cell *link = run[idx];
				if (link && has_coord(cell, NORTH))
					add_cell_link(link, NORTH, get_neighbour(link, NORTH), true);
				// clear run;
				for (int i = 0; i < g->columns; ++i)
					run[i] = NULL;
				ptr = 0;
			}
			else
				add_cell_link(cell, EAST, get_neighbour(cell, EAST), true);
		}
	}
}
