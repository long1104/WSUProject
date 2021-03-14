#ifndef APPS_H_
#define APPS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "ExercisePlan.h"
#include "DietPlan.h"

using namespace std;

class FitnessAppWrapper {
  public:
    void runApp();
    void loadDailyPlan(fstream &fileStream, DietPlan &plan);
    void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);
    void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
    void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
    void editDailyPlan(int day, int options, DietPlan plan[]);
    void editDailyPlan(int day, int options, ExercisePlan plan[]);
    ostream& displayDailyPlan(ostream &output, const DietPlan& plan);
    ostream& displayDailyPlan(ostream &output, const ExercisePlan& plan);
    ostream& displayWeeklyPlan(ostream& output, const DietPlan plan[]);
    ostream& displayWeeklyPlan(ostream& output, const ExercisePlan plan[]);
    ofstream& storeDailyPlan(ofstream &output, const DietPlan& plan);
    ofstream& storeDailyPlan(ofstream &fileWrite, const ExercisePlan& plan);
    ofstream& storeWeeklyPlan(ofstream &fileWrite, const DietPlan plan[]);
    ofstream& storeWeeklyPlan(ofstream &fileWrite, const ExercisePlan plan[]);
    void displayMenu();
    ~FitnessAppWrapper();

  private:
    DietPlan *dietPlan_;
    ExercisePlan *exercPlan_;
    fstream inputFileDiet_;
    fstream inputFileExercise_;
};

#endif