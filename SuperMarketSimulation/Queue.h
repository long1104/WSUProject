#include <iostream>
#include "QueueNode.h"

class Queue {
  public:
    Queue(): pHead(nullptr), pTail(nullptr) {}
    void enqueue(QueueNode *node);
    Data dequeue();
    void printQueue();
    bool isEmpty() {return pHead == NULL;};
    ~Queue();
  private:
    QueueNode *pHead;
    QueueNode *pTail;
};