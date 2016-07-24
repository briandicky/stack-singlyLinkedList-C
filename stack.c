#include <stdlib.h>
#include "stack.h"

void push(struct stack* this, int x)
{
	struct stack_layer *new = malloc(sizeof(struct stack_layer));
	new->num = x;
	new->next = NULL;

	if(this->top == NULL)
		this->top = new;
	else {
		new->next = this->top;
		this->top = new;
	}
	this->sp++;
//    this->stk[++this->sp] = x;
}

int pop(struct stack* this)
{
	if(this->top == NULL) return -1;
	else {
		int temp;
		struct stack_layer *temp_layer;
		temp = this->top->num;
		temp_layer = this->top;
		this->top = this->top->next;
		free(temp_layer);
		this->sp--;
		if(this->sp == 0) free(this);
		return temp;
	}
//    return this->stk[this->sp--];
}

struct stack* new_stack()
{
    struct stack* stk = malloc(sizeof(struct stack));
    stk->sp = -1;
	stk->top = NULL;
    return stk;
}

void delete_stack(struct stack* stk)
{
	if(stk->top == NULL) return;
	else {
		struct stack_layer *temp;
		while(stk->top != NULL) {
			temp = stk->top;
			stk->top = stk->top->next;
			free(temp);
		}
	}
    free(stk);
}

