#include "Data.h"

class QueueNode {
  public:
    QueueNode(Data *pData, QueueNode *pNext): pData(pData), pNext(pNext) {}
    Data *getData() {return pData;};
    void setNextNode(QueueNode *node);
    QueueNode *getNextNode();
    string ToString();
  private:
    Data *pData;
    QueueNode *pNext;
};