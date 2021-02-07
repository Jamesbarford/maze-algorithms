#ifndef CELL_H
#define CELL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

enum Directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef uint8_t Direction;

struct Coords;
struct Cell;

typedef struct Coords
{
	uint8_t bitmap;
	struct Cell *links[4];
} Coords;

typedef struct Cell
{
	uint32_t row;
	uint32_t column;
	struct Coords *coords;
	struct Coords *cell_link_map;
} Cell;

Cell *create_cell(uint32_t row, uint32_t column);
Cell *get_link(Cell *cell, Direction direction);
Cell *get_neighbour(Cell *cell, Direction direction);
void free_cell(Cell *cell);
bool has_coord(Cell *cell, Direction direction);
void set_coord(Cell *cell, Direction direction, Cell *link);

Coords *create_coords();

bool unlinked_cell(Cell *cell);
bool add_cell_link(Cell *link, Direction direction, Cell *cell, bool bidirectional);
bool has_link(Cell *cell, Direction direction);
void set_link(Cell *link, Direction direction, Cell *cell);

#endif
