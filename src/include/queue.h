#ifndef _QUEUE_H_
#define _QUEUE_H_

struct queue;
int queue_new (struct queue * * pp_queue, int capacity);
int queue_delete (struct queue * p_queue);

int queue_put (struct queue * p_queue, void const * p_obj);
int queue_get (struct queue * p_queue, void const * * pp_obj);

#endif
