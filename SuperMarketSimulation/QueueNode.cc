#include "QueueNode.h"

string QueueNode::ToString() {
  return "{" + pData->ToString() + "}";
}

Data* QueueNode::getData() {
  return pData;
}