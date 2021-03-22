#include "Queue.h"

using namespace std;

void Queue::enqueue(QueueNode *node) {
  if (pHead == NULL) {
    pHead = node;
    pTail = node;
  } else {
    pTail->setNextNode(node);
    pTail = node;
  }
  return;
}

void Queue::dequeue() {
  if (pHead == pTail) {
    pHead = NULL;
    pTail = NULL;
  } else {
    pHead = pHead->getNextNode();
  }
}

void Queue::printQueue() {
  QueueNode *current = pHead;
  if (pHead != NULL) {
    cout << current->ToString();
    current = current->getNextNode();
  }
  while (current != NULL) {
    cout << ", " << current->ToString();
    current = current->getNextNode();
  }
}