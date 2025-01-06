#include "src/queue.h"
#include "src/stack.h"

int main() {
  Queue *queue = createQueue();
  populateQueue(queue);
  printQueue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  printQueue(queue);
  clearQueue(queue);
  Stack *stack = createStack();
  populateStack(stack);
  printStack(stack);
  pop(stack);
  printStack(stack);
  clearStack(stack);
}
