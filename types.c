#include <stddef.h>
#include "sindri.h"

size_t
sindri_typesize(sindri_objtype type) {
	switch(type) {
		case CONS:
			return sizeof(sindri_cons);
		default:
			return 0;
	}
}

size_t
sindri_objsize(const sindri_object *obj) {
	return sindri_typesize(obj->type);
}
