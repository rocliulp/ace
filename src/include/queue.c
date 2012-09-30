#include <stdlib.h>
#include <error_codes.h>

struct queue {
  int capacity;
  void const * * p_array;
  int head;
  int tail;
};

int queue_new (struct queue * * pp_queue, int capacity) {
  void * p_array = NULL;
  struct queue * p_queue = NULL;
  if (pp_queue == NULL) return EC_NULL_POINTER;
  if (capacity < 1) return EC_NULL_POINTER;

  p_array = malloc (capacity * sizeof (void *));
  if (p_array == NULL) return EC_OUT_OF_MEMORY;
  p_queue = malloc (sizeof (struct queue));
  if (p_queue == NULL) {
    free (p_array);
    return EC_OUT_OF_MEMORY;
  }
  p_queue -> capacity = capacity;
  p_queue -> p_array = p_array;
  p_queue -> head = -1;
  p_queue -> tail = -1;

  *pp_queue = p_queue;

  return EC_OK;
}

int queue_delete (struct queue * p_queue) {
  return EC_OK;
}

int queue_put (struct queue * p_queue, void const * p_obj) {
  return EC_OK;
}

int queue_get (struct queue * p_queue, void const * * pp_obj) {
  return EC_OK;
}


