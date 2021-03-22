#include <iostream>
#include "QueueNode.h"

string QueueNode::ToString() {
  return "{" + pData->ToString() + "}";
}

void QueueNode::setNextNode(QueueNode *node) {
  pNext = node;
}

Data *QueueNode::getData() {
  return pData;
}

QueueNode *QueueNode::getNextNode() {
  return pNext;
}