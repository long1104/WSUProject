#include "Queue.h"

int main() {
  Queue expLane;
  Queue normLane;
  int runtime;
  cout << "Give the runtime for simulation: ";
  cin >> runtime;
  int timeElapse = 0;
  int expArrivalTime = (rand() % 5) + 1;
  int normArrivalTime = (rand() % 6) + 3;

  Data *expCustomer = new Data(1, (rand() % 5) + 1, 0);
  Data *normCustomer = new Data(1, (rand() % 6) + 3, 0);

  int expCustomerId = 1;
  int normCustomerId = 1;

  for (timeElapse; timeElapse < runtime; timeElapse++) {
    if (timeElapse == expArrivalTime || (timeElapse == expCustomer->getTotalTime())) {
      expLane.enqueue(new QueueNode(expCustomer, nullptr));
      cout << "At " << timeElapse << " : Customer with ID " << expCustomer->getCustomerNumber() << " in Express queue" << endl;
    }

    if (timeElapse == normArrivalTime || (timeElapse == normCustomer->getTotalTime())) {
      expLane.enqueue(new QueueNode(normCustomer, nullptr));
      cout << "At " << timeElapse << " : Customer with ID " << normCustomer->getCustomerNumber() << " in Normal queue" << endl;
    }
    if (timeElapse == expCustomer->getTotalTime()) {
      Data temp = expLane.dequeue();
      cout << "Customer with ID " << temp.getCustomerNumber() << " was in line " << temp.getTotalTime() << " mins" << endl;
      int expServiceTime = (rand() % 5) + 1;
      expCustomerId++;
      if (expCustomerId > 24*60) {
        expCustomerId = 1;
      }
      expCustomer = new Data(expCustomerId, expServiceTime, expServiceTime + temp.getTotalTime());
    }

    if (timeElapse == normCustomer->getTotalTime()) {
      Data temp = normLane.dequeue();
      cout << "Customer with ID " << temp.getCustomerNumber() << " was in line " << temp.getTotalTime() << " mins" << endl;
      int normServiceTime = (rand() % 5) + 1;
      normCustomerId++;
      if (normCustomerId > 24*60) {
        normCustomerId = 1;
      }
      normCustomer = new Data(normCustomerId, normServiceTime, normServiceTime + temp.getTotalTime());
    }

    if (timeElapse % 10 == 0 && timeElapse != 0) {
      cout << "***********EXPRESS LANE***********" << endl;
      expLane.printQueue();

      cout << "***********NORMAL LANE***********" << endl;
      normLane.printQueue();
    }
  }
}