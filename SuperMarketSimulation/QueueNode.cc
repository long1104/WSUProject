#include <iostream>
#include "QueueNode.h"

string QueueNode::ToString() {
  return "{" + pData->ToString() + "}";
}

void QueueNode::setNextNode(QueueNode *node) {
  pNext = node;
}

QueueNode *QueueNode::getNextNode() {
  return pNext;
}