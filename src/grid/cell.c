#include "cell.h"

Cell *create_cell(unsigned int row, unsigned int column)
{
	Cell *cell = malloc(sizeof(*cell));
	if (cell == NULL)
		fprintf(stderr, "Not enough memory to create cell \n");

	cell->row = row;
	cell->column = column;
	cell->coords = create_coords();
	cell->cell_link_map = create_cell_links();

	return cell;
}

Coords *create_coords()
{
	Coords *coords = malloc(sizeof(*coords));
	if (coords == NULL)
		fprintf(stderr, "Not enough memory to create coordinates for cell \n");

	coords->north = coords->south = coords->east = coords->west = NULL;
	coords->bitmap = 0;

	return coords;
}

void set_coord(Coords *coords, Direction direction)
{
	coords->bitmap |= 1 << direction;
}

bool has_coord(Coords *coords, Direction direction)
{
	return coords->bitmap >> direction & 1;
}

CellLinks *create_cell_links()
{
	CellLinks *cell_link_map = malloc(sizeof(*cell_link_map));
	if (cell_link_map == NULL)
		fprintf(stderr, "Not enough memory to create cell links for cell \n");

	cell_link_map->north = cell_link_map->south = cell_link_map->east = cell_link_map->west = NULL;

	return cell_link_map;
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
		link->cell_link_map->north = cell;
		if (bidirectional && cell != NULL)
			cell->cell_link_map->south = link;
		return true;

	case SOUTH:
		link->cell_link_map->south = cell;
		if (bidirectional && cell != NULL)
			cell->cell_link_map->north = link;
		return true;

	case EAST:
		link->cell_link_map->east = cell;
		if (bidirectional && cell != NULL)
			cell->cell_link_map->west = link;
		return true;

	case WEST:
		link->cell_link_map->west = cell;
		if (bidirectional && cell != NULL)
			cell->cell_link_map->east = link;
		return true;

	default:
		return false;
	}
}

bool free_cell_link(CellLinks *cell_link_map, Direction direction)
{
	switch (direction)
	{
	case NORTH:
		free(cell_link_map->north);
		return true;
	case SOUTH:
		free(cell_link_map->south);
		return true;
	case EAST:
		free(cell_link_map->east);
		return true;
	case WEST:
		free(cell_link_map->west);
		return true;

	default:
		return false;
	}
}

Cell *get_link(Cell *cell, Direction direction)
{
	if (cell == NULL)
		return NULL;
	switch (direction)
	{
	case NORTH:
		return cell->cell_link_map->north;
	case SOUTH:
		return cell->cell_link_map->south;
	case EAST:
		return cell->cell_link_map->east;
	case WEST:
		return cell->cell_link_map->west;
	default:
		return NULL;
	}
}

Cell *get_neighbour(Cell *cell, Direction direction)
{
	if (cell == NULL)
		return NULL;
	switch (direction)
	{
	case NORTH:
		return cell->coords->north;
	case SOUTH:
		return cell->coords->south;
	case EAST:
		return cell->coords->east;
	case WEST:
		return cell->coords->west;
	default:
		return NULL;
	}
}

bool unlinked_cell(Cell *cell)
{
	return cell->cell_link_map->north == NULL &&
		   cell->cell_link_map->south == NULL &&
		   cell->cell_link_map->east == NULL &&
		   cell->cell_link_map->west == NULL;
}
