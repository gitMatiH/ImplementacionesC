#ifndef SET_H
#define SET_H

#include "hash_table.h"

typedef struct set set;

set *set_create(void);
void set_add(set *s, void *element);
void set_remove(set *s, void *element);
int set_contains(set *s, void *element);
int set_is_empty(set *s);
void set_clear(set *s);
void set_destroy(set *s);

#endif
