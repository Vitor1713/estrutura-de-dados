#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int length(Stack *stack) {
  return stack->length;
}

void push(Stack *stack, int value) {
  stack->length++;
  if(stack->length == 1) {
    stack->values = malloc(stack->length * sizeof(int));
  }else {
    stack->values = realloc(stack->values, stack->length * sizeof(int));
  }
  stack->values[stack->length - 1] = value;
  stack->top = &stack->values[stack->length - 1];
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
    return 1;
  }
  return 0;
}
 
void printStack(Stack *stack) {
  if(!isEmpty(stack)) {
    for(int i = stack->length - 1; i >= 0; i--) {
      printf("%i", stack->values[i]);
      if(i == 0) {
        continue;
      }
      printf(" - ");
    }
    printf("\nElemento do topo: %i", *peek(stack));
    printf("\nNumero de elementos: %i", length(stack));
  }else {
    printf("Pilha vazia! \n"); 
  }
}

void populateStack(Stack *stack) {
  int length, min, max = 0;
  srand(time(NULL));
  printf("Digite o tamanho da pilha: \n");
  scanf("%i", &length);
  printf("Digite um valor minimo: \n");
  scanf("%i", &min);
  printf("Digite um valor maximo: \n");
  scanf("%i", &max);
  for(int i = 0; i < length; i++) {
    push(stack, rand() % max + min);
  }
}

int main () {
  Stack *stack = createStack();
  populateStack(stack);
  printStack(stack);
}
