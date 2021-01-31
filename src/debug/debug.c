#include "debug.h"

void print_top(unsigned int columns);

void print_maze(unsigned int rows, unsigned int columns, Cell *grid[rows][columns])
{
	print_top(columns);
	for (int row = 0; row < rows; ++row)
	{

		for (int column = 0; column < columns; ++column)
		{
			Cell *cell = grid[row][column];

			printf("%c", cell->cell_link_map->east != NULL ? ' ' : '|');
			printf("   ");
			printf("%c", '+');
			printf("%s",cell->cell_link_map->south != NULL ? "   " : "---");
			printf("%c", '+');
		}
		printf("\n");
	}
}

void print_top(unsigned int columns)
{
	printf("+");
	for (int i = 0; i < columns; ++i)
		printf("---+");
	printf("\n");
}
