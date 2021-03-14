#include "FitnessAppWrapper.h"

using namespace std;

void FitnessAppWrapper::runApp() {
  dietPlan_ = new DietPlan[7];
  exercPlan_ = new ExercisePlan[7];
  inputFileDiet_.open("dietPlans.txt");
  inputFileExercise_.open("exercisePlans.txt");
  ofstream dietFileWrite("dietPlansWrite.txt");
  ofstream exerciseFileWrite("exercisePlansWrite.txt");
  bool exit = false;
  while (!exit) {
    displayMenu();
    int value;
    cin >> value;
    int day;
    int option;
    switch (value){
      case 1:
        cout << "Loading diet plans ..." << endl;
        loadWeeklyPlan(inputFileDiet_, dietPlan_);
        break;

      case 2:
        /* code */
        cout << "Loading exercise plans ..." << endl;
        loadWeeklyPlan(inputFileExercise_, exercPlan_);
        break;

      case 3:
        /* code */
        storeWeeklyPlan(dietFileWrite, dietPlan_);
        break;

      case 4:
        /* code */
        storeWeeklyPlan(exerciseFileWrite, exercPlan_);
        break;

      case 5:
        /* code */
        displayWeeklyPlan(cout, dietPlan_);
        break;

      case 6:
        /* code */
        displayWeeklyPlan(cout, exercPlan_);
        break;

      case 7:
        /* code */
        cout << "   Please enter which days to edit (1 - 7): ";
        cin >> day;
        cout << "               1. Edit goal" << endl;
        cout << "               2. Edit plane name" << endl;
        cout << "               3. Edit date" << endl;
        cout << "        Please select what to edit:" << endl;
        cin >> option;
        editDailyPlan(day, option, dietPlan_);
        displayWeeklyPlan(cout, dietPlan_);
        break;

      case 8:
        /* code */
        cout << "   Please enter which days to edit (1 - 7): ";
        cin >> day;
        cout << "               1. Edit goal" << endl;
        cout << "               2. Edit plane name" << endl;
        cout << "               3. Edit date" << endl;
        cout << "        Please select what to edit:" << endl;
        cin >> option;
        editDailyPlan(day, option, exercPlan_);
        displayWeeklyPlan(cout, exercPlan_);
        break;

      case 9:
        exit = true;
        storeWeeklyPlan(dietFileWrite, dietPlan_);
        storeWeeklyPlan(exerciseFileWrite, exercPlan_);
        break;

      default:
        cout << "Command is invalid" << endl;
        break;
    }
  }
  dietFileWrite.close();
  exerciseFileWrite.close();
  inputFileDiet_.close();
  inputFileExercise_.close();
}

void FitnessAppWrapper::editDailyPlan(int day, int option, ExercisePlan plan[]) {
  switch (option){
    case 1:
      /* code */
      plan[day - 1].editGoal();
      break;

    default:
      cout << "    Please input edit values: ";
      string value;
      getline(cin, value);
      if (option == 2) {
        plan[day - 1].setPlanName(value);
      } else {
        plan[day - 1].setDate(value);
      }
      break;
  }
}

void FitnessAppWrapper::editDailyPlan(int day, int option, DietPlan plan[]) {
  switch (option){
    case 1:
      /* code */
      plan[day - 1].editGoal();
      break;

    default:
      cout << "    Please input edit values: ";
      string value;
      getline(cin, value);
      if (option == 2) {
        plan[day - 1].setPlanName(value);
      } else {
        plan[day - 1].setDate(value);
      }
      break;
  }
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan) {
  fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, ExercisePlan &plan) {
  fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]) {
  int i = 0;
  while(!fileStream.eof()) {
    DietPlan temp;
    loadDailyPlan(fileStream, temp);
    weeklyPlan[i] = temp;
    i++;
  }
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]) {
  int i = 0;
  while(!fileStream.eof()) {
    ExercisePlan temp;
    loadDailyPlan(fileStream, temp);
    weeklyPlan[i] = temp;
    cout << temp << endl;
    i++;
  }
}

ostream& FitnessAppWrapper::displayDailyPlan(ostream &output, const DietPlan& plan) {
  output << plan;
  return output;
}

ostream& FitnessAppWrapper::displayDailyPlan(ostream &output, const ExercisePlan& plan) {
  output << plan;
  return output;
}

ostream& FitnessAppWrapper::displayWeeklyPlan(ostream& output, const DietPlan plan[]) {
  for(int i = 0; i < 7; i++) {
    displayDailyPlan(output, plan[i]);
    cout << endl;
  }
  return output;
}

ostream& FitnessAppWrapper::displayWeeklyPlan(ostream& output, const ExercisePlan plan[]) {
  for(int i = 0; i < 7; i++) {
    displayDailyPlan(output, plan[i]);
    cout << endl;
  }
  return output;
}

ofstream& FitnessAppWrapper::storeDailyPlan(ofstream &fileWrite, const DietPlan& plan) {
  fileWrite << plan;
  return fileWrite;
}

ofstream& FitnessAppWrapper::storeDailyPlan(ofstream &fileWrite, const ExercisePlan& plan) {
  fileWrite << plan;
  return fileWrite;
}

ofstream& FitnessAppWrapper::storeWeeklyPlan(ofstream &fileWrite, const DietPlan plan[]) {
  for(int i = 0; i < 7; i++) {
    displayDailyPlan(fileWrite, plan[i]);
  }
  return fileWrite;
}

ofstream& FitnessAppWrapper::storeWeeklyPlan(ofstream &fileWrite, const ExercisePlan plan[]) {
  for(int i = 0; i < 7; i++) {
    displayDailyPlan(fileWrite, plan[i]);
  }
  return fileWrite;
}

void FitnessAppWrapper::displayMenu() {
  cout << "1. Load weekly diet plan from file" << endl;
  cout << "2. Load weekly exercise plan from file." << endl;
  cout << "3. Store weekly diet plan to file." << endl;
  cout << "4. Store weekly exercise plan to file." << endl;
  cout << "5. Display weekly diet plan to screen." << endl;
  cout << "6. Display weekly exercise plan to screen." << endl;
  cout << "7. Edit daily diet plan." << endl;
  cout << "8. Edit daily exercise plan." << endl;
  cout << "9. Exit" << endl;
  cout << "Please choose the following options: ";
}

FitnessAppWrapper::~FitnessAppWrapper() {
  inputFileDiet_.close();
  inputFileExercise_.close();
}
