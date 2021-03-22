#include <iostream>
#include "QueueNode.h"

class Queue {
  public:
    Queue(): pHead(NULL), pTail(NULL) {}
    void enqueue(QueueNode *node);
    void dequeue();
    void printQueue();
  private:
    QueueNode *pHead;
    QueueNode *pTail;
};