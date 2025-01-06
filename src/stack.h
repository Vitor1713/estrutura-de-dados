#ifndef _STACK_
#define _STACK_

typedef struct Stack Stack;

struct Stack {
  int *values;
  int *top;
  int length;
}; 

Stack* createStack();

int lengthStack(Stack *stack);

void push(Stack *stack, int value);

int isEmptyStack(Stack *stack);

int pop(Stack *stack);

int *peek(Stack *stack);
 
void printStack(Stack *stack);

void populateStack(Stack *stack);

void clearStack(Stack *stack);

#endif
