#ifndef btree_H
#define btree_H

#include <stdio.h>
#include <stdbool.h>

#include "../EstructuraGrafo23.h"

typedef struct btree_s *btree_t;
/*
 * Note: The definition of the structure should be in [btree.c], not here.
 */

btree_t btree_empty(void);
/* Creates an empty btreeionary
 *
 * PRE: {true}
 *   btree = btree_empty();
 * POS: {btree --> btree_t /\ btree_length(btree) == 0}
 */

btree_t btree_add(btree_t btree, u32 nodo, u32 vecino);


void *btree_dump(btree_t btree);


btree_t btree_destroy(btree_t btree);

#endif
