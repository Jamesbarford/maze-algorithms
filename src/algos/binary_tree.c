#include "mazealgorithms.h"

void binary_tree_link(unsigned int rows, unsigned int columns, Cell *grid[rows][columns])
{
	for (unsigned int row = 0; row < rows; ++row)
	{
		for (unsigned int column = 0; column < columns; ++column)
		{
			Cell *cell = grid[row][column];

			if (cell->coords->north == NULL)
			{
				add_cell_link(cell, EAST, cell->coords->east, true);
				return;
			}
			else if (cell->coords->east == NULL)
			{
				add_cell_link(cell, NORTH, cell->coords->north, true);
				return;
			}

			int random = rand() % 2;
			Direction direction = random == NORTH ? NORTH : EAST;

			add_cell_link(cell, direction, direction == NORTH ? cell->coords->north : cell->coords->east, true);
		}
	}
}
