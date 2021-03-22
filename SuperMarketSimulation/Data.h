#ifndef DATA_H_
#define DATA_H_

#include <string>

using namespace std;

class Data {
  public:
    Data(const int customerNumber, const int serviceTime, const int totalTime): customerNumber_(customerNumber), serviceTime_(serviceTime_), totalTime_(totalTime) {}
    int getCustomerNumber() const {return customerNumber_;};
    int getServiceTime() const {return serviceTime_;};
    int getTotalTime() const {return totalTime_;};
    void setCustomerNumber(const int number);
    void setServiceTime(const int time);
    void setTotalTime(const int time);
    string ToString() const;
  private:
    int customerNumber_;
    int serviceTime_;
    int totalTime_;
};

#endif   //DATA_H_