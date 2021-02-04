#include <stdlib.h>
#include <stdio.h>

#include "./distances.h"

Distances *create_distances(Cell *root, unsigned int rows, unsigned int columns)
{
	Distances *distances = (Distances *)malloc(sizeof(distances) + rows * columns * sizeof(Cell));
	if (distances == NULL)
		fprintf(stderr, "Failed to allocate memory for 'Distances'\n");

	distances->root = root;
	distances->rows = rows;
	distances->columns = columns;

	return distances;
}

void track_distance(Distances *distances, Cell *cell, unsigned int distance)
{
	Track *track = (Track *)malloc(sizeof(Track));
	if (track == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for 'Track'");
	}
	if (cell == NULL)
		return;

	track->column = cell->column;
	track->row = cell->row;
	track->distance = distance;

	distances->tracks[track->row * distances->rows + track->column] = track;
}

Track *get_track(Distances *distances, unsigned int row, unsigned int column)
{

	return distances->tracks[row * distances->rows + column];
}

Distances *calculate_distances(Grid *grid)
{
	Cell *root = get_cell(grid, 0, 0);

	unsigned int size = grid->rows * grid->columns;
	unsigned int c = 0;
	unsigned int temp_count = 0;

	Distances *distances = create_distances(root, grid->rows, grid->columns);
	Cell *current_run[size];
	Cell *new_run[size];

	track_distance(distances, root, 0);

	current_run[0] = root;

	while (current_run[0] != NULL)
	{
		while ((root = current_run[c++]) != NULL)
		{
			for (int d = 0; d < 4; ++d)
			{
				Cell *link = get_link(root, d);
				if (link != NULL)
				{
					Track *track = get_track(distances, link->row, link->column);
					if (track == NULL)
					{
						Track *track = get_track(distances, root->row, root->column);
						track_distance(distances, link, track->distance + 1);
						new_run[temp_count++] = link;
					}
				}
			}
		}

		for (int i = 0; i < size; ++i)
		{
			current_run[i] = new_run[i];
			new_run[i] = NULL;
		}

		c = 0;
		temp_count = 0;
	}

	return distances;
}

// TODO: actually find shortest path
Distances *find_shortest_path(Grid *grid, Cell *end)
{
	Cell *root = get_cell(grid, 0, 0);
	Cell *current = end;
	Distances *distances = calculate_distances(grid);
	track_distance(distances, root, 0);

	while (current->row != root->row && current->column != root->column)
	{
		for (int d = 0; d < 4; ++d)
		{
			Cell *link = get_link(current, d);
		}
	}
}

void print_distances(Distances *distances)
{
	for (int i = 0; i < distances->rows * distances->columns; ++i)
	{
		Track *track = distances->tracks[i];
		if (track)
			printf("row: %d, column %d, distance: %d\n", track->row, track->column, track->distance);
	}
}

void free_distances(Distances *distances)
{
	for (int i = 0; i < distances->rows * distances->columns; ++i)
	{
		Track *track = distances->tracks[i];
		if (track)
			free(track);
	}
	free(distances);
}
