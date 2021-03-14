#include <iostream>
#include "ExercisePlan.h"

using namespace std;

ExercisePlan::ExercisePlan(const ExercisePlan& other) {
  goal_ = other.goal_;
  planName_ = other.planName_;
  date_ = other.date_;
}

void ExercisePlan::setGoal(int goal) {
  goal_ = goal;
}

void ExercisePlan::editGoal() {
  int value;
  cout << "Please give new goal" << endl;
  cin >> value;
  ExercisePlan::setGoal(value);
}

void ExercisePlan::setPlanName(string planName) {
  planName_ = planName;
}

void ExercisePlan::setDate(string date) {
  date_ = date;
}

ExercisePlan::~ExercisePlan() {
  planName_.~string();
  date_.~string();
}

ostream& operator<<(ostream &out, const ExercisePlan& plan) {
  out << " " << plan.getPlanName() << endl <<  plan.getGoal() << endl << plan.getDate() << endl;
}

istream& operator>>(istream& in, ExercisePlan& plan) {
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