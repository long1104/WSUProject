#include "FitnessAppWrapper.h"

using namespace std;

// int main(int argc, char **argv) {
//   ifstream file;
//   file.open("textfile.txt", ifstream::in);
//   ofstream fileToWrite("write.txt");
//   vector<DietPlan> dietPlans;
//   DietPlan a;
//   int i = 0;
//   while (!file.eof()) {
//     DietPlan temp;
//     // loadDailyPlan(file, temp);
//     dietPlans.push_back(temp);
//     cout << temp;
//     // file >> arr[i];
//     // cout << arr[i];
//     // fileToWrite << arr[i];
//     i++;
//   }
//   return EXIT_SUCCESS;
// }

void FitnessAppWrapper::runApp() {
  dietPlan_ = new DietPlan[7];
  exercPlan_ = new ExercisePlan[7];
  inputFileDiet_.open("dietPlans.txt");
  inputFileExercise_.open("exercisePlans.txt");
  ofstream dietFileWrite("dietPlansWrite.txt");
  ofstream exerciseFileWrite("exercisePlansWrite.txt");
  int value;
  cin >> value;
  bool exit = false;
  while (!exit) {
    displayMenu();
    switch (value){
      case 1:
        loadWeeklyPlan(inputFileDiet_, dietPlan_);
        break;

      case 2:
        /* code */
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
        break;

      case 8:
        /* code */
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
  inputFileDiet_.close();
  inputFileExercise_.close();
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
  }
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]) {
  int i = 0;
  while(!fileStream.eof()) {
    ExercisePlan temp;
    loadDailyPlan(fileStream, temp);
    weeklyPlan[i] = temp;
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
  }
  return output;
}

ostream& FitnessAppWrapper::displayWeeklyPlan(ostream& output, const ExercisePlan plan[]) {
  for(int i = 0; i < 7; i++) {
    displayDailyPlan(output, plan[i]);
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
  // loadWeeklyPlan(inputFileDiet_, dietPlan_);
  // loadWeeklyPlan(inputFileExercise_, exercPlan_);
  // ofstream dietFile("dietPlansWrite.txt");
  // ofstream exerciseFile("exercisePlansWrite.txt");
  // storeWeeklyPlan(dietFile, dietPlan_);
  // storeWeeklyPlan(exerciseFile, exercPlan_);
  // displayWeeklyPlan(cout, dietPlan_);
  // displayWeeklyPlan(cout, exercPlan_);
  // dietFile.close();
  // exerciseFile.close();
  cout << "Please choose the following options:" << endl;
  cout << "1. Load weekly diet plan from file" << endl;
  cout << "2. Load weekly exercise plan from file." << endl;
  cout << "3. Store weekly diet plan to file." << endl;
  cout << "4. Store weekly exercise plan to file." << endl;
  cout << "5. Display weekly diet plan to screen." << endl;
  cout << "6. Display weekly exercise plan to screen." << endl;
  cout << "7. Edit daily diet plan." << endl;
  cout << "8. Edit daily exercise plan.e" << endl;
  cout << "9. Exit" << endl;
}

FitnessAppWrapper::~FitnessAppWrapper() {
  inputFileDiet_.close();
  inputFileExercise_.close();
}
