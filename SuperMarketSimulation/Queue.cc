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

Data Queue::dequeue() {
  if (pHead != NULL) {
    Data returnData = *(pHead->getData());
    if (pHead == pTail) {
      delete pHead;
      pHead = NULL;
      pTail = NULL;
    } else {
      QueueNode *temp = pHead;
      delete temp;
      pHead = pHead->getNextNode();
    }
    return returnData;
  }
  return Data();
}

void Queue::printQueue() {
  QueueNode *current = pHead;
  if (isEmpty()) {
    cout << "Empty Queue!!!" << endl;
  }
  if (pHead != NULL) {
    cout << current->ToString();
    current = current->getNextNode();
  }
  while (current != NULL) {
    cout << ", " << current->ToString();
    current = current->getNextNode();
  }
  cout << endl;
}

Queue::~Queue() {
  while (!isEmpty()) {
    dequeue();
  }
}