#include "grid.h"

Grid *init_grid(unsigned int rows, unsigned int columns)
{
	Grid *grid = allocate_grid(rows, columns);
	Cell *cell;

	for (int row = 0; row < rows; ++row)
	{
		for (int column = 0; column < columns; ++column)
		{
			short coord_count = 0;
			cell = get_cell(grid, row, column);

			int north_row = row - 1;
			if (in_bounds(grid, north_row, column))
			{
				cell->coords->north = get_cell(grid, north_row, column);
				++coord_count;
				set_coord(cell->coords, NORTH);
			}
			else
			{
				cell->coords->north = NULL;
			}

			int south_row = row + 1;
			if (in_bounds(grid, south_row, column))
			{
				cell->coords->south = get_cell(grid, south_row, column);
				++coord_count;
				set_coord(cell->coords, SOUTH);
			}
			else
			{
				cell->coords->south = NULL;
			}

			int east_column = column + 1;
			if (in_bounds(grid, row, east_column))
			{
				cell->coords->east = get_cell(grid, row, east_column);
				++coord_count;
				set_coord(cell->coords, EAST);
			}
			else
			{
				cell->coords->east = NULL;
			}

			int west_column = column - 1;
			if (in_bounds(grid, row, west_column))
			{
				cell->coords->west = get_cell(grid, row, west_column);
				++coord_count;
				set_coord(cell->coords, WEST);
			}
			else
			{
				cell->coords->west = NULL;
			}

			printf("row : %d,column:  %d, bmp: %d\n", cell->row, cell->column, cell->coords->bitmap);
		}
	}

	return grid;
}

Cell *get_cell(Grid *grid, unsigned int row, unsigned int column)
{
	return grid->board[row * grid->rows + column];
}

Grid *allocate_grid(unsigned int rows, unsigned int columns)
{
	Grid *grid = (Grid *)malloc(sizeof(Grid) + rows * columns * sizeof(Cell));

	if (grid == NULL)
		fprintf(stderr, "Failed to allocate memory to create grid \n");

	unsigned int count = 0;
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			grid->board[count++] = create_cell(i, j);

	grid->rows = rows;
	grid->columns = columns;
	grid->size = rows * columns;

	return grid;
}

void free_grid(Grid *grid)
{
	free(grid);
}

unsigned int random_row(Grid *grid)
{
	return rand() % grid->rows;
}

unsigned int random_column(Grid *grid)
{
	return rand() % grid->columns;
}

bool in_bounds(Grid *grid, unsigned int row, unsigned int column)
{
	return row < grid->rows && column < grid->columns;
}
