#ifndef CELL_LIST_H
#define CELL_LIST_H

#include <stdint.h>
#include "cell.h"

typedef struct CellNode
{
	struct Cell *cell;
	struct CellNode *next;
} CellNode;

CellNode *create_cell_node();
CellNode *get_node_at(CellNode *node, uint32_t idx);
void add_cell_node(CellNode *node, Cell *cell);
void remove_cell_node(CellNode *node, Cell *cell);
void remove_head();

#endif
