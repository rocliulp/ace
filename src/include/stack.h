/*
 * @author Paul Liu
 * @summary This is the interface of stack class.
 */

#ifndef _STACK_H_
#define _STACK_H_

struct stack;

int stack_new (struct stack * * pp_stack, int capacity);
int stack_delete (struct stack * p_stack);

int stack_pop (struct stack * p_stack, void const * * pp_obj);
int stack_push (struct stack * p_stack, void const * p_obj);
int stack_get_top (struct stack const * p_stack, void const * * pp_obj);
int stack_is_empty (struct stack const * p_stack, int * empty);

int stack_print (struct stack const * p_stack);

/*
 * Should there be a method of get_top ()
 */

#endif


