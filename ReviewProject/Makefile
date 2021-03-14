CC = g++
CFLAGS = -Wall -std=c++11 -g

all: app

app: FitnessAppWrapper.o ExercisePlan.o DietPlan.o
				$(CC) $(CFLAGS) -o app FitnessAppWrapper.o ExercisePlan.o DietPlan.o

FitnessAppWrapper.o: FitnessAppWrapper.cc ExercisePlan.h DietPlan.h
				$(CC) $(CFLAGS) -c FitnessAppWrapper.cc

ExercisePlan.o: ExercisePlan.cc ExercisePlan.h
				$(CC) $(CFLAGS) -c ExercisePlan.cc

DietPlan.o: DietPlan.cc DietPlan.h
				$(CC) $(CFLAGS) -c DietPlan.cc

clean:
	rm -f *.o *~