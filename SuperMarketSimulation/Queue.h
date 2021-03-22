#include "QueueNode.h"

class Queue {
  public:
    Queue(): pHead(NULL), pTail(NULL) {}
    void enqueue(QueueNode *node);
    void dequeue(QueueNode *node);
    void printQueue();
  private:
    QueueNode *pHead;
    QueueNode *pTail;
};