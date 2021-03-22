#include "Data.h"

using namespace std;

void Data::setCustomerNumber(const int number) {
  customerNumber_ = number;
}

void Data::setServiceTime(const int time) {
  serviceTime_ = time;
}

void Data::setTotalTime(const int time) {
  totalTime_ = time;
}

string Data::ToString() const {
  string returnString = "Customer " + customerNumber_;
  returnString += " service time: " + serviceTime_ ;
  return returnString;
}