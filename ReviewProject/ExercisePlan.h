#ifndef EXERCISEPLAN_H_
#define EXERCISEPLAN_H_

#include <string>
#include <iostream>

using namespace std;

class ExercisePlan {
  public:
    ExercisePlan(const int goalCal, const string planName, const string date) : goal_(goalCal), planName_(planName), date_(date) {}
		ExercisePlan(){};
    ExercisePlan(const ExercisePlan& other);
    int getGoal() const {return goal_;};
    string getPlanName() const {return planName_;};
    string getDate() const {return date_;};
    void editGoal();
    void setGoal(int goal);
    void setPlanName(string planName);
    void setDate(string date);
    ~ExercisePlan();
    // string ToString() const;

  private:
    int goal_;
    string planName_;
    string date_;
};

istream& operator>>(istream& in, ExercisePlan& plan);
ostream& operator<<(ostream &out, const ExercisePlan& plan);

#endif    // EXERCISEPLAN_H_