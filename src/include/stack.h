/*
 * @author Paul Liu
 * @summary This is the interface of stack class.
 */

#ifndef _STACK_H_
#define _STACK_H_

struct stack;

extern int stack_new (struct stack * * pp_stack, int capacity);
extern int stack_delete (struct stack * p_stack);

extern int stack_pop (struct stack * p_stack, void const * * p_obj);
extern int stack_push (struct stack * p_stack, void const * p_obj);
extern int stack_is_empty (struct stack const * p_stack, int * empty);

extern int stack_print (struct stack const * p_stack);

/*
 * Should there be a method of get_top ()
 */

#endif


