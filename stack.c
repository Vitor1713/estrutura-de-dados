#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;

struct Stack {
  int *values;
  int *top;
  int length;
}; 

Stack* createStack() {
  Stack *stack = malloc(sizeof(Stack));

  stack->length = 0;
  stack->values = malloc(sizeof(int));
  stack->top = malloc(sizeof(int));

  return stack;
}

int length(Stack *stack) {
  return stack->length;
}

void push(Stack *stack, int value) {
  stack->length++;
  stack->values[stack->length - 1] = value;
  stack->top = stack->values[stack->length - 1];
  stack->values = realloc(stack->values, (stack->length + 1) * sizeof(int));
} 

int pop(Stack *stack) {
  int pop;

  return pop;
}

int *peek(Stack *stack) {
  return stack->top;
}

int isEmpty(Stack *stack) {
  if(stack->length == 0) {
    return 0;
  }

  return 1;
}

int main () {
  Stack *stack = createStack(); 
  push(stack, 30);
  printf("tamanho: %i\n", stack->length);
  printf("topo: %i", *stack->top);
}



