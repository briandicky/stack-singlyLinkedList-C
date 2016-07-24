#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 100

struct stack_layer {
	int num;
	struct stack_layer *next;
};

struct stack {
    int sp;
//    int stk[STACK_SIZE];
	struct stack_layer *top;
};

extern void push(struct stack* this, int x);
extern int pop(struct stack* this);
extern struct stack* new_stack();
extern void delete_stack(struct stack* stk);

#endif
