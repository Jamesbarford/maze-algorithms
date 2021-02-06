#include "mazealgorithms.h"

void binary_tree_link(Grid *g)
{
	for (unsigned int row = 0; row < g->rows; ++row)
	{
		for (unsigned int column = 0; column < g->columns; ++column)
		{
			Cell *cell = get_cell(g, row, column);

			if (!has_coord(cell, NORTH))
				add_cell_link(cell, EAST, get_neighbour(cell, EAST), true);
			else if (!has_coord(cell, EAST))
				add_cell_link(cell, NORTH, get_neighbour(cell, NORTH), true);
			else
			{
				Direction direction = rand() % 2 == NORTH ? NORTH : EAST;

				add_cell_link(cell, direction, get_neighbour(cell, direction), true);
			}
		}
	}
}
