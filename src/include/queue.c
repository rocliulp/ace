#include <stdlib.h>
#include <stdio.h>
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
  if (p_queue == NULL) return EC_NULL_POINTER;
  if (p_queue -> p_array != NULL) free (p_queue -> p_array);
  free (p_queue);
  return EC_OK;
}

int queue_put (struct queue * p_queue, void const * p_obj) {
  if (p_queue == NULL) return EC_NULL_POINTER;
  if (p_obj == NULL) return EC_NULL_POINTER;
  if (p_queue -> p_array == NULL) return EC_NULL_POINTER;

  if (p_queue -> tail == p_queue -> head) {
    if (p_queue -> head == -1) {
      ++ (p_queue -> tail);
      p_queue -> p_array [p_queue -> tail] = p_obj;
    } else {
      return EC_OUT_OF_RANGE;
    }
  } else if (p_queue -> tail > p_queue -> head) {
    if (p_queue -> tail < p_queue -> capacity - 1) {
      ++ (p_queue -> tail);
      p_queue -> p_array [p_queue -> tail] = p_obj;
    } else if (p_queue -> tail == p_queue -> capacity - 1) {
      if (p_queue -> head > 0) {
        p_queue -> tail = 0;
        p_queue -> p_array [p_queue -> tail] = p_obj;
      } else {
        return EC_OUT_OF_RANGE;
      }
    } else {
      return EC_OUT_OF_RANGE;
    }
  } else {
    if (p_queue -> tail < p_queue -> head - 1) {
      ++ (p_queue -> tail);
      p_queue -> p_array [p_queue -> tail] = p_obj;
    } else {
      return EC_OUT_OF_RANGE;
    }
  }
  return EC_OK;
}

int queue_get (struct queue * p_queue, void const * * pp_obj) {
  if (p_queue == NULL) return EC_NULL_POINTER;
  if (pp_obj == NULL) return EC_NULL_POINTER;
  if (p_queue -> p_array == NULL) return EC_NULL_POINTER;

  if (p_queue -> head < p_queue -> tail) {
    ++ (p_queue -> head);
    * pp_obj = p_queue -> p_array [p_queue -> head];
  } else if (p_queue -> head > p_queue -> tail) {
    if (p_queue -> head < p_queue -> capacity - 1) {
      ++ (p_queue -> head);
      * pp_obj = p_queue -> p_array [p_queue -> head];
    } else if (p_queue -> head == p_queue -> capacity - 1) {
      if (p_queue -> tail > -1) {
        p_queue -> head = 0;
        * pp_obj = p_queue -> p_array [p_queue -> head];
      } else {
        return EC_OUT_OF_RANGE;
      }
    } else {
    }
  } else {
    return EC_OUT_OF_RANGE;
  }

  if (p_queue -> head == p_queue -> tail) {
    p_queue -> head = -1;
    p_queue -> tail = -1;
  }

  return EC_OK;
}

int queue_is_empty (struct queue const * p_queue, int * empty) {
  if (p_queue == NULL) return EC_NULL_POINTER;
  if (empty == NULL) return EC_NULL_POINTER;
  if (p_queue -> p_array == NULL) return EC_NULL_POINTER;
  if (p_queue -> head == p_queue -> tail) {
    if (p_queue -> head == -1) {
      * empty = 1;
    } else {
      return EC_OUT_OF_RANGE;
    }
  } else {
    * empty = 0;
  }
  return EC_OK;
}

int queue_print (struct queue const * p_queue) {
  int i = -1;
  if (p_queue == NULL) return EC_NULL_POINTER;
  if (p_queue -> p_array == NULL) return EC_NULL_POINTER;
  
  if (p_queue -> head < p_queue -> tail) {
    i = p_queue -> head;
    while (++ i < p_queue -> tail + 1) {
      putchar (* ((char *)(p_queue -> p_array [i])));
    }
  } else if (p_queue -> head > p_queue -> tail) {
    i = p_queue -> head;
    while (++i < p_queue -> capacity) {
      putchar (* ((char *)(p_queue -> p_array [i])));
    }
    i = -1;
    while (++i < p_queue -> tail + 1) {
      putchar (* ((char *)(p_queue -> p_array [i])));
    }
  }
  printf ("\n\r");
  return EC_OK;
}
