#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

struct _s_list
{
  list_elem * elems;
  u32 len;
  u32 cap;
};

list list_empty()
{
  list s = malloc(sizeof(struct _s_list));
  s->len = 0;
  s->cap = 0;
  s->elems = NULL;
  return s;
}

list list_push(list s, list_elem e)
{
  assert(s != NULL);
  assert(s->cap >= s->len);
  // Reservar memoria si es necesario
  if(s->cap == s->len) {
    size_t newcap = s->len == 0 ? 1 : 2*s->len;
    s->elems = realloc(s->elems, newcap*sizeof(list_elem));
    s->cap = newcap;
  }
  (s->elems)[s->len] = e;
  //printf("\nse agrego : %i", e);
  ++(s->len);

  return s;
}

list list_pop(list s)
{
  assert(s != NULL);
  --(s->len);
  return s;
}

u32 list_size(list s)
{
  assert(s != NULL);
  return s->len;
}

list_elem list_top(list s)
{
  assert(s != NULL);
  assert(s->len > 0);
  assert(s->elems != NULL);
  return s->elems[(s->len)-1];
}

bool list_is_empty(list s)
{
  assert(s != NULL);
  return s->len == 0;
}

void list_change_elem(list s, u32 index, u32 newName){//changes the name of the indexed vecino
  assert(s != NULL);
  assert(s->len > 0);
  assert(s->elems != NULL);
  s->elems[index] = newName;
  return;
}

list_elem list_by_index(list s, u32 index) {
  assert(s != NULL);
  assert(s->len > 0);
  assert(s->elems != NULL);
  return s->elems[index];
}

list_elem *list_to_array(list s)
{
  assert(s != NULL);
  list_elem *arr = NULL;
  if(s->len) {
    arr = calloc(s->len, sizeof(list_elem));
    arr = memcpy(arr, s->elems, s->len*sizeof(list_elem));
  }
  return arr;
}

list list_destroy(list s) //falta implementar
{
  assert(s != NULL);
  free(s->elems);
  free(s);
  return NULL;
}
