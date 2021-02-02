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

	return coords;
}

CellLinks *create_cell_links()
{
	CellLinks *cell_link_map = malloc(sizeof(*cell_link_map));
	if (cell_link_map == NULL)
		fprintf(stderr, "Not enough memory to create cell links for cell \n");

	return cell_link_map;
}

void free_cell(Cell *cell)
{
	free(cell->cell_link_map);
	free(cell->coords);
	free(cell);
}

bool is_linked(Cell *cell, Cell *query)
{
	return cell->cell_link_map->north != NULL ||
		   cell->cell_link_map->south != NULL ||
		   cell->cell_link_map->east != NULL ||
		   cell->cell_link_map->west != NULL;
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
		cell_link_map->north = NULL;
		return true;
	case SOUTH:
		free(cell_link_map->south);
		cell_link_map->south = NULL;
		return true;
	case EAST:
		free(cell_link_map->east);
		cell_link_map->east = NULL;
		return true;
	case WEST:
		free(cell_link_map->west);
		cell_link_map->west = NULL;
		return true;

	default:
		return false;
	}
}

// https://stackoverflow.com/a/15397992 c-pointer-to-array-of-pointers-to-structures, is this a good idea 🤔
Cell **get_neighbors(Cell *cell)
{
	struct Cell **hash_table[5];

	hash_table[NORTH] = &cell->coords->north;
	hash_table[SOUTH] = &cell->coords->south;
	hash_table[EAST] = &cell->coords->east;
	hash_table[WEST] = &cell->coords->west;
	hash_table[4] = '\0';

	return *hash_table;
}
