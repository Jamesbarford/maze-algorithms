#include "cell_list.h"

CellNode *create_cell_node()
{
	CellNode *node = malloc(sizeof(CellNode));
	if (node == NULL)
		fprintf(stderr, "Failed to allocate memory for 'CellNode'\n");

	node->cell = NULL;
	node->next = NULL;

	return node;
}

CellNode *get_node_at(CellNode *node, unsigned int idx)
{
	CellNode *current = node;
	if (idx == 0)
		return current;

	unsigned int ptr = 0;
	while (current->next != NULL && ptr++ != idx)
		current = current->next;

	return current;
}

void add_cell_node(CellNode *node, Cell *cell)
{
	CellNode *current = node;
	if (current->cell == NULL)
	{
		current->cell = cell;
		return;
	}

	while (current->next != NULL)
		current = current->next;

	current->next = create_cell_node();
	current->next->cell = cell;
	current->next->next = NULL;
}

void remove_cell_node(CellNode *node, Cell *cell)
{
	CellNode *current = node;
	if (current->cell == cell)
		remove_head(current);

	while (current->next != NULL && current->next->cell != NULL)
	{
		if (current->next->cell == cell)
			break;

		current = current->next;
		if (current == NULL)
			return;
	}

	current->next = current->next->next;
	free(current);
}

void remove_head(CellNode *node)
{
	CellNode *current = node;
	if (current->next == NULL)
		return;

	if (node->next != NULL)
	{
		node->cell = node->next->cell;
		node->next = node->next->next;

		if (current != NULL)
			free(current);
	}
}
