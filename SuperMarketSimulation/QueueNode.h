#include "Data.h"

class QueueNode {
  public:
    QueueNode(Data *pData, QueueNode *pNext): pData(pData), pNext(pNext) {}
    Data* getData() {return pData;};
    string ToString();
  private:
    Data *pData;
    QueueNode *pNext;
};