#include "cell.h"

Cell *create_cell(unsigned int row, unsigned int column)
{
	Cell *cell = malloc(sizeof(*cell));
	if (cell == NULL)
		fprintf(stderr, "Not enough memory to create cell \n");

	cell->row = row;
	cell->column = column;
	cell->coords = create_coords();
	cell->cell_link_map = create_coords();

	return cell;
}

Coords *create_coords()
{
	Coords *coords = malloc(sizeof(*coords));
	if (coords == NULL)
		fprintf(stderr, "Not enough memory to create coordinates for cell \n");

	coords->bitmap = 0;
	for (int i = 0; i < 4; ++i)
		coords->links[i] = NULL;

	return coords;
}

void set_coord(Cell *cell, Direction direction, Cell *link)
{
	cell->coords->bitmap |= 1 << direction;
	cell->coords->links[direction] = link;
}

bool has_coord(Cell *cell, Direction direction)
{
	return cell->coords->bitmap >> direction & 1;
}

void free_cell(Cell *cell)
{
	free(cell->cell_link_map);
	free(cell->coords);
	free(cell);
}

bool add_cell_link(Cell *link, Direction direction, Cell *cell, bool bidirectional)
{
	switch (direction)
	{
	case NORTH:
		set_link(link, NORTH, cell);
		if (bidirectional && cell != NULL)
			set_link(cell, SOUTH, link);
		return true;

	case SOUTH:
		set_link(link, SOUTH, cell);
		if (bidirectional && cell != NULL)
			set_link(cell, NORTH, link);
		return true;

	case EAST:
		set_link(link, EAST, cell);
		if (bidirectional && cell != NULL)
			set_link(cell, WEST, link);
		return true;

	case WEST:
		set_link(link, WEST, cell);
		if (bidirectional && cell != NULL)
			set_link(cell, EAST, link);
		return true;

	default:
		return false;
	}
}

void set_link(Cell *link, Direction direction, Cell *cell)
{
	link->cell_link_map->bitmap |= 1 << direction;
	link->cell_link_map->links[direction] = cell;
}

Cell *get_link(Cell *cell, Direction direction)
{
	if (cell == NULL || !has_link(cell, direction))
		return NULL;

	return cell->cell_link_map->links[direction];
}

Cell *get_neighbour(Cell *cell, Direction direction)
{
	if (cell == NULL || !has_coord(cell, direction))
		return NULL;

	return cell->coords->links[direction];
}

bool unlinked_cell(Cell *cell)
{
	return cell->cell_link_map->bitmap == 0;
}

bool has_link(Cell *cell, Direction direction)
{
	return cell->cell_link_map->bitmap >> direction & 1;
}
