#ifndef CELL_H
#define CELL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

enum Directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef unsigned short Direction;

struct Coords;
struct Cell;
struct CellLinks;

typedef struct CellLinks
{
	struct Cell *north;
	struct Cell *south;
	struct Cell *east;
	struct Cell *west;
} CellLinks;

typedef struct Coords
{
	struct Cell *north;
	struct Cell *south;
	struct Cell *east;
	struct Cell *west;
} Coords;

typedef struct Cell
{
	unsigned int row;
	unsigned int column;
	struct Coords *coords;
	struct Coords *cell_link_map;
} Cell;

Cell *create_cell(unsigned int row, unsigned int column);
Cell **get_neighbors(Cell *cell);

Coords *create_coords();

CellLinks *create_cell_links();
bool add_cell_link(Cell *link, Direction direction, Cell *cell, bool bidirectional);
bool free_cell_link(CellLinks *cell_link_map, Direction direction);

bool is_linked(Cell *cell, Cell *query);

#endif
