#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue Queue;

struct Queue {
  int *values;
  int *first;
  int length;
};

Queue *createQueue() {
  Queue *queue = malloc(sizeof(Queue));

  queue->length = 0;
  queue->first = malloc(sizeof(int));
  queue->values = NULL;

  return queue;
}

int isEmpty(Queue *queue) {
  if (queue->length == 0) {
    return 1;
  }

  return 0;
}

int length(Queue *queue) { return queue->length; }

void enqueue(Queue *queue, int value) {
  queue->length++;
  if (queue->length == 1) {
    queue->values = malloc(sizeof(int));
    queue->first = &queue->values[0];
  } else {
    queue->values = realloc(queue->values, queue->length * sizeof(int));
  }

  queue->values[queue->length - 1] = value;
}

int dequeue(Queue *queue) {
  if(isEmpty(queue)) return -1;

  int element = queue->values[0];
  queue->length--;
  for(int i = 0; i < queue->length; i++) {
    queue->values[i] = queue->values[i + 1];
  };

  queue->values = realloc(queue->values, queue->length * sizeof(int));
  queue->first = &queue->values[0];

  return element;
}

void printQueue(Queue *queue) {
  printf("\n");
  if(!isEmpty(queue)) {
    for(int i = 0; i < queue->length; i++) {
      printf("%i", queue->values[i]);
      if(queue->length == (i + 1)) break;
      printf(" - ");
    }
    printf("\nElemento da frente: %i", *queue->first);
    printf("\nNumero de elementos: %i", queue->length);
  }else {
    printf("Fila vazia!");
  }
}

void populateQueue(Queue *queue) {
  int size, min, max = 0;
  printf("\n");
  printf("Digite o tamanho da fila: ");
  scanf("%i", &size);
  printf("Digite o valor minimo da fila: ");
  scanf("%i", &min);
  printf("Digite o valor maximo da fila: ");
  scanf("%i", &max);
  srand(time(NULL));

  for(int i = 0; i < size; i++) {
    enqueue(queue, rand() % max + min);
  }
}

void clearQueue(Queue *queue) {
  free(queue->values);
  free(queue);
}

int main() {
  Queue *queue = createQueue();
  populateQueue(queue);
  printQueue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  printQueue(queue);
  clearQueue(queue);
}
