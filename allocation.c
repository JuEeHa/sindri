#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sindri.h"
#include "types.h"

sindri_object*
sindri_alloc_object(sindri_heap *heap, sindri_objtype type) {
	sindri_cons *allocated;
	sindri_object *obj;
	
	obj = malloc(sindri_typesize(type));
	if(obj == NULL)
		return NULL;
	obj->type = type;
	
	allocated = malloc(sizeof(sindri_cons));
	if(allocated == NULL)
		return NULL;
	allocated->type = CONS;
	allocated->car = obj;
	allocated->cdr = (sindri_object*)heap->allocated;
	heap->allocated = allocated;
	
	return obj;
}

sindri_cons*
sindri_alloc_cons(sindri_heap *heap) {
	sindri_cons *cons;
	cons = (sindri_cons*)sindri_alloc_object(heap, CONS);
	cons->car = NULL;
	cons->cdr = NULL;
	return cons;
}

sindri_integer*
sindri_alloc_integer(sindri_heap *heap) {
	sindri_integer *integer;
	integer = (sindri_integer*)sindri_alloc_object(heap, INTEGER);
	integer->size = 0;
	integer->negative = false;
	integer->digits = NULL;
	return integer;
}
