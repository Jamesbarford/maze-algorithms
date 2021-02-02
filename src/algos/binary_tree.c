#include "mazealgorithms.h"

void binary_tree_link(Grid *g)
{
	srand(time(NULL));
	Cell *cell;
	for (unsigned int row = 0; row < g->rows; ++row)
	{
		for (unsigned int column = 0; column < g->columns; ++column)
		{
			cell = &g->board[row][column];

			if (cell->coords->north == NULL)
				add_cell_link(cell, EAST, cell->coords->east, true);
			else if (cell->coords->east == NULL)
				add_cell_link(cell, NORTH, cell->coords->north, true);
			else
			{
				int random = rand() % 2;
				Direction direction = random == NORTH ? NORTH : EAST;

				add_cell_link(cell, direction, direction == NORTH ? cell->coords->north : cell->coords->east, true);
			}
		}
	}
}
