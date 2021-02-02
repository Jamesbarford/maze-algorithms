#include "debug.h"

void print_top(unsigned int columns);

void print_maze(Grid *g)
{
	print_top(g->columns);
	for (int row = 0; row < g->rows; ++row)
	{
		printf("|");
		char top[g->columns * 3];
		for (int column = 0; column < g->columns; ++column)
		{
			Cell *cell = &g->board[row][column];
			printf("   ");
			printf("%c", cell->cell_link_map->east != NULL ? ' ' : '|');
			printf("%c", '+');
			printf("%s", cell->cell_link_map->south != NULL ? "   " : "---");
			printf("%c", '+');
		}
		printf("|");
		printf("\n");
		top[0]='\0';
	}
}

void print_top(unsigned int columns)
{
	printf("+");
	for (int i = 0; i < columns; ++i)
		printf("---+");
	printf("\n");
}
