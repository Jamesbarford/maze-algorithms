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
	short bitmap;
} Coords;

typedef struct Cell
{
	unsigned int row;
	unsigned int column;
	struct Coords *coords;
	struct CellLinks *cell_link_map;
} Cell;

Cell *create_cell(unsigned int row, unsigned int column);
Cell *get_link(Cell *cell, Direction direction);
Cell *get_neighbour(Cell *cell, Direction direction);
void free_cell(Cell *cell);
bool has_coord(Coords *coords, Direction direction);
void set_coord(Coords *coords, Direction direction);

Coords *create_coords();
CellLinks *create_cell_links();

bool unlinked_cell(Cell *cell);
bool add_cell_link(Cell *link, Direction direction, Cell *cell, bool bidirectional);
bool free_cell_link(CellLinks *cell_link_map, Direction direction);

#endif
