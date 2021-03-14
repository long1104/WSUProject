#ifndef DIETPLAN_H_
#define DIETPLAN_H_

#include <string>
#include <iostream>

using namespace std;

class DietPlan {
  public:
    DietPlan(const int goalCal, const string planName, const string date) : goal_(goalCal), planName_(planName), date_(date) {}
    DietPlan(){};
    DietPlan(const DietPlan& other);
    int getGoal() const {return goal_;};
    string getPlanName() const {return planName_;};
    string getDate() const {return date_;};
    void editGoal();
    void setGoal(int goal);
    void setPlanName(string planName);
    void setDate(string date);
    ~DietPlan();
    // string ToString() const;

  private:
    int goal_;
    string planName_;
    string date_;
};

istream& operator>>(istream& in, DietPlan& plan);
ostream& operator<<(ostream &out, const DietPlan& plan);


#endif    // DIETPLAN_H_