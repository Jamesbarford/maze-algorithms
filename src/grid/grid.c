#include "grid.h"

Grid *create_grid(unsigned int rows, unsigned int columns)
{
	struct Grid *grid = malloc(sizeof(*grid));
	struct Cell *cell_values = (Cell *)calloc(rows * columns, sizeof(Cell));
	struct Cell **board = (Cell **)malloc(rows * sizeof(Cell *));

	if (grid == NULL)
		fprintf(stderr, "Failed to allocate memory to create grid \n");

	if (cell_values == NULL)
		fprintf(stderr, "Failed to allocate memory for cells \n");

	if (board == NULL)
		fprintf(stderr, "Failed to allocate memory for rows \n");

	for (int i = 0; i < rows; ++i)
		board[i] = cell_values + i * rows;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			board[i][j].cell_link_map = create_cell_links();
			board[i][j].coords = create_coords();
			board[i][j].row = i;
			board[i][j].column = j;
		}
	}

	grid->board = board;
	grid->rows = rows;
	grid->columns = columns;
	grid->size = rows * columns;

	return grid;
}

unsigned int random_row(Grid *self)
{
	return rand() % self->rows;
}

unsigned int random_column(Grid *self)
{
	return rand() % self->columns;
}

bool in_bounds(unsigned int MAX_ROW, unsigned int MAX_COL, unsigned int row, unsigned int column)
{
	return row < MAX_ROW && column < MAX_COL;
}
