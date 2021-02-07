#include "debug.h"

#define ROW_COUNT 3000

void print_top(uint32_t columns);

void print_maze(Grid *g)
{
	char top[ROW_COUNT];
	char bottom[ROW_COUNT];

	print_top(g->columns);
	for (uint32_t row = 0; row < g->rows; ++row)
	{
		strcat(top, "|");
		strcat(bottom, "+");

		for (uint32_t column = 0; column < g->columns; ++column)
		{
			Cell *cell = get_cell(g, row, column);

			strcat(top, "   ");
			if (cell && has_link(cell, EAST))
				strcat(top, " ");
			else
				strcat(top, "|");

			if (cell && has_link(cell, SOUTH))
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

void print_top(uint32_t columns)
{
	printf("+");
	for (uint32_t i = 0; i < columns; ++i)
		printf("---+");
	printf("\n");
}

void print_solution(Grid *g, Distances *shortest_path)
{
	char top[ROW_COUNT];
	char bottom[ROW_COUNT];

	print_top(g->columns);
	for (uint32_t row = 0; row < g->rows; ++row)
	{
		strcat(top, "|");
		strcat(bottom, "+");

		for (uint32_t column = 0; column < g->columns; ++column)
		{
			Cell *cell = get_cell(g, row, column);
			Track *track = get_track(shortest_path, cell->row, cell->column);

			if (track != NULL)
			{
				strcat(top, " # ");
			}
			else
			{
				strcat(top, "   ");
			}

			if (cell && has_link(cell, EAST))
				strcat(top, " ");
			else
				strcat(top, "|");

			if (cell && has_link(cell, SOUTH))
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

void print_grid(Grid *g)
{
	for (uint32_t i = 0; i < g->rows; ++i)
		for (uint32_t j = 0; j < g->columns; ++j)
		{
			Cell *cell = get_cell(g, i, j);
			printf("row: %d, column: %d, coords: 0x%x\n", cell->row, cell->column, cell->coords->bitmap);
		}
}
