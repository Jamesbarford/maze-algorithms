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

void track_distance(Distances *distances, unsigned int row, unsigned int column, unsigned int distance)
{
	Track *track = (Track *)malloc(sizeof(Track));
	if (track == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for 'Track'");
	}

	track->column = column;
	track->row = row;
	track->distance = distance;

	distances->tracks[track->row * distances->rows + track->column] = track;
}

Track *get_track(Distances *distances, unsigned int row, unsigned int column)
{
	if (row > distances->rows || column > distances->columns)
		return NULL;
	return distances->tracks[row * distances->rows + column];
}

Distances *calculate_distances(Grid *grid)
{
	Cell *root = get_cell(grid, 0, 0);

	unsigned int size = grid->rows * grid->columns;
	unsigned int c = 0;
	unsigned int temp_count = 0;

	Distances *distances = create_distances(root, grid->rows, grid->columns);

	Cell **current_run = malloc(size * sizeof(Cell *));
	Cell **new_run = malloc(size * sizeof(Cell *));

	track_distance(distances, 0, 0, 0);

	current_run[0] = root;

	while (current_run[0] != NULL)
	{
		while ((root = current_run[c++]) != NULL)
		{
			for (int direction = 0; direction <= WEST; ++direction)
			{
				Cell *link = get_link(root, direction);
				if (link != NULL)
				{
					Track *track = get_track(distances, link->row, link->column);
					if (track == NULL)
					{
						Track *prev = get_track(distances, root->row, root->column);
						track_distance(distances, link->row, link->column, prev->distance + 1);
						new_run[temp_count++] = link;
					}
				}
			}
		}

		int i = 0;
		for (; i < size; ++i)
		{
			current_run[i] = new_run[i];
			new_run[i] = NULL;
		}
		current_run[i + 1] = (Cell *)'\0';

		c = 0;
		temp_count = 0;
	}

	free(new_run);
	free(current_run);

	return distances;
}

Distances *find_shortest_path(Distances *distances, Cell *start, Cell *end)
{
	Cell *current = end;
	Distances *shortest_path = create_distances(start, distances->rows, distances->columns);
	Track *current_track = get_track(distances, current->row, current->column);
	Track *goal = get_track(distances, 0, 0);

	track_distance(shortest_path, current->row, current->column, 0);

	while (current_track != goal)
	{
		for (int d = 0; d < 4; ++d)
		{
			Cell *link = get_link(current, d);
			if (link != NULL)
			{
				Track *next_track = get_track(distances, link->row, link->column);
				if (next_track != NULL && next_track->distance < current_track->distance)
				{
					track_distance(shortest_path, link->row, link->column, next_track->distance);
					current_track = next_track;
					current = link;
				}
			}
		}
	}

	return shortest_path;
}

Track *find_longest_path(Distances *distances)
{
	Track *max = NULL;

	int max_distance = 0;

	for (unsigned int i = 0; i < distances->rows * distances->columns; ++i)
	{
		Track *t = distances->tracks[i];
		if (t->distance > max_distance)
		{
			max_distance = t->distance;
			max = t;
		}
	}

	return max;
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
