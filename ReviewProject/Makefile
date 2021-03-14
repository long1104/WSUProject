CC = g++
CFLAGS = -Wall -std=c++11 -g

all: app

app: clientSide.o FitnessAppWrapper.o ExercisePlan.o DietPlan.o
				$(CC) $(CFLAGS) -o app clientSide.o FitnessAppWrapper.o ExercisePlan.o DietPlan.o

clientSide.o: clientSide.cc FitnessAppWrapper.h
				$(CC) $(CFLAGS) -c clientSide.cc

FitnessAppWrapper.o: FitnessAppWrapper.cc ExercisePlan.h DietPlan.h
				$(CC) $(CFLAGS) -c FitnessAppWrapper.cc

ExercisePlan.o: ExercisePlan.cc ExercisePlan.h
				$(CC) $(CFLAGS) -c ExercisePlan.cc

DietPlan.o: DietPlan.cc DietPlan.h
				$(CC) $(CFLAGS) -c DietPlan.cc

clean:
	rm -f *.o *~