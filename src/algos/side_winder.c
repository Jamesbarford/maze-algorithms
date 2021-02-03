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
			cell = &g->board[row][column];
			run[ptr++] = cell;

			bool at_east = cell->coords->east == NULL;
			bool at_north = cell->coords->north == NULL;
			bool close_run = at_east || (!at_north && (rand() % 2) == 0);

			if (close_run)
			{
				int idx = rand() % ptr;
				Cell *link = run[idx];
				if (link && link->coords->north != NULL)
					add_cell_link(link, NORTH, link->coords->north, true);
				// clear run;
				for (int i = 0; i < g->columns; ++i)
					run[i] = NULL;
				ptr = 0;
			}
			else
				add_cell_link(cell, EAST, cell->coords->east, true);
		}
	}
}
