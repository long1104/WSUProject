#include <iostream>
#include "DietPlan.h"

using namespace std;

DietPlan::DietPlan(const DietPlan& other) {
  goal_ = other.goal_;
  planName_ = other.planName_;
  date_ = other.date_;
}

void DietPlan::setGoal(int goal) {
  goal_ = goal;
}

void DietPlan::editGoal() {
  int value;
  cout << "Please give new goal" << endl;
  cin >> value;
  DietPlan::setGoal(value);
}

void DietPlan::setPlanName(string planName) {
  planName_ = planName;
}

void DietPlan::setDate(string date) {
  date_ = date;
}

DietPlan::~DietPlan() {
  planName_.~string();
  date_.~string();
}

ostream& operator<<(ostream &out, const DietPlan& plan) {
  out << plan.getPlanName() << endl <<  plan.getGoal() << endl << plan.getDate() << endl;
  return out;
}

istream& operator>>(istream& in, DietPlan& plan) {
  int goal;
  string planName;
  string date;
  getline(in, planName);
  plan.setPlanName(planName);
  in >> goal;
  plan.setGoal(goal);
  in.ignore(1024, '\n');
  getline(in, date);
  plan.setDate(date);
  in.ignore(1024, '\n');
  return in;
}