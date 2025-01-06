#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef _STACK_
#define _STACK_

typedef struct Stack Stack;

struct Stack {
  int *values;
  int *top;
  int length;
}; 

Stack* createStack() {
  Stack *stack = malloc(sizeof(Stack));

  stack->length = 0;
  stack->values = NULL;
  stack->top = malloc(sizeof(int));
  return stack;
}

int lengthStack(Stack *stack) {
  return stack->length;
}

void push(Stack *stack, int value) {
  stack->length++;
  if(stack->length == 1) {
    stack->values = malloc(sizeof(int));
  }else {
    stack->values = realloc(stack->values, stack->length * sizeof(int));
  }
  stack->values[stack->length - 1] = value;
  stack->top = &stack->values[stack->length - 1];
}

int isEmptyStack(Stack *stack) {
  if(stack->length == 0) {
    return 1;
  }
  return 0;
}

int pop(Stack *stack) {
  if(isEmptyStack(stack)) {
    printf("Pilha Vazia!");
    return -1;
  }

  int pop = stack->values[stack->length - 1];
  
  stack->length--;

  if ((stack->length) == 0) {
    stack->values = malloc(sizeof(int));
  } else {
    stack->values = realloc(stack->values, stack->length * sizeof(int));
  }

  stack->top = &stack->values[stack->length -1];
  
  return pop;
}

int *peek(Stack *stack) {
  return stack->top;
}
 
void printStack(Stack *stack) {
  printf("\n");
  if(!isEmptyStack(stack)) {
    for(int i = stack->length - 1; i >= 0; i--) {
      printf("%i", stack->values[i]);
      if(i == 0) {
        continue;
      }
      printf(" - ");
    }
    printf("\nElemento do topo: %i", *peek(stack));
    printf("\nNumero de elementos: %i", lengthStack(stack));
  }else {
    printf("Pilha vazia! \n"); 
  }
}

void populateStack(Stack *stack) {
  int size, min, max = 0;
  srand(time(NULL));
  printf("Digite o tamanho da pilha: \n");
  scanf("%i", &size);
  printf("Digite um valor minimo: \n");
  scanf("%i", &min);
  printf("Digite um valor maximo: \n");
  scanf("%i", &max);
  for(int i = 0; i < size; i++) {
    push(stack, rand() % max + min);
  }
}

void clearStack(Stack *stack) {
  free(stack->values);
  free(stack);
}

#endif
