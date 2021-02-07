#ifndef DISTANCES_H
#define DISTANCES_H

#include <stdint.h>
#include "./cell.h"
#include "grid.h"

typedef struct Track
{
	uint32_t distance;
	uint32_t row;
	uint32_t column;
} Track;

typedef struct Distances
{
	Cell *root;
	uint32_t rows;
	uint32_t columns;
	Track *tracks[];
} Distances;

Distances *create_distances(Cell *root, uint32_t rows, uint32_t columns);
Distances *calculate_distances(Grid *grid);
Distances *find_shortest_path(Distances *distances, Cell *start, Cell *end);
Track *find_longest_path(Distances *distances);

void track_distance(Distances *distances, uint32_t row, uint32_t column, uint32_t distance);
void print_distances(Distances *distances);
void free_distances(Distances *distances);

Track *get_track(Distances *distances, uint32_t row, uint32_t column);

#endif
