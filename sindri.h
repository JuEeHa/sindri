/* Datatypes */
typedef enum {CONS} sindri_objtype;

struct sindri_object {
	sindri_objtype type;
	const char data[];
};
typedef struct sindri_object sindri_object;

struct sindri_cons {
	sindri_objtype type;
	struct sindri_object *car, *cdr;
};
typedef struct sindri_cons sindri_cons;

struct sindri_heap {
	sindri_cons *allocated;
	size_t head_size;
	sindri_object *head;
};
typedef struct sindri_heap sindri_heap;
