#include "debug.h"

#define ROW_COUNT 3000

void print_top(unsigned int columns);

void print_maze(Grid *g)
{
	char top[ROW_COUNT];
	char bottom[ROW_COUNT];

	print_top(g->columns);
	for (int row = 0; row < g->rows; ++row)
	{
		strcat(top, "|");
		strcat(bottom, "+");

		for (int column = 0; column < g->columns; ++column)
		{
			Cell *cell = get_cell(g, row, column);

			strcat(top, "   ");
			if (cell && cell->cell_link_map->east != NULL)
				strcat(top, " ");
			else
				strcat(top, "|");

			if (cell && cell->cell_link_map->south != NULL)
				strcat(bottom, "   ");
			else
				strcat(bottom, "---");

			strcat(bottom, "+");
		}

		printf("%s\n", top);
		printf("%s\n", bottom);
		memset(top, '\0', ROW_COUNT);
		memset(bottom, '\0', ROW_COUNT);
	}
}

void print_top(unsigned int columns)
{
	printf("+");
	for (int i = 0; i < columns; ++i)
		printf("---+");
	printf("\n");
}

void print_solution(Grid *g, Distances *shortest_path)
{
	char top[ROW_COUNT];
	char bottom[ROW_COUNT];

	print_top(g->columns);
	for (int row = 0; row < g->rows; ++row)
	{
		strcat(top, "|");
		strcat(bottom, "+");

		for (int column = 0; column < g->columns; ++column)
		{
			Cell *cell = get_cell(g, row, column);
			Track *track = get_track(shortest_path, cell->row, cell->column);

			if (track != NULL) {
				strcat(top, " # ");
			} else {
				strcat(top, "   ");
			}
			
			if (cell && cell->cell_link_map->east != NULL)
				strcat(top, " ");
			else
				strcat(top, "|");

			if (cell && cell->cell_link_map->south != NULL)
				strcat(bottom, "   ");
			else
				strcat(bottom, "---");

			strcat(bottom, "+");
		}

		printf("%s\n", top);
		printf("%s\n", bottom);
		memset(top, '\0', ROW_COUNT);
		memset(bottom, '\0', ROW_COUNT);
	}
}
