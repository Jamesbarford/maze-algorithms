#ifndef DISTANCES_H
#define DISTANCES_H

#include "./cell.h"
#include"grid.h"

typedef struct Track
{
	unsigned int distance;
	unsigned int row;
	unsigned int column;
} Track;

typedef struct Distances
{
	Cell *root;
	unsigned int rows;
	unsigned int columns;
	Track *tracks[];
} Distances;


Distances *create_distances(Cell *root, unsigned int rows, unsigned int columns);
Distances *calculate_distances(Grid *grid);
Distances *find_shortest_path(Grid *grid, Cell *end);

void track_distance(Distances *distances, Cell *cell, unsigned int distance);
void print_distances(Distances *distances);
void free_distances(Distances *distances);

Track *get_track(Distances *distances, unsigned int row, unsigned int column);

#endif
