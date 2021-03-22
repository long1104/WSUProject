CC = g++
CFLAGS = -Wall -std=c++11 -g

all: simulation

simulation: Simulation.o Queue.o QueueNode.o Data.o
				$(CC) $(CFLAGS) -o simulation Simulation.o Queue.o QueueNode.o Data.o

Simulation.o: Simulation.cc Queue.h
				$(CC) $(CFLAGS) -c Simulation.cc

Queue.o: Queue.cc Queue.h
				$(CC) $(CFLAGS) -c Queue.cc

QueueNode.o: QueueNode.cc QueueNode.h
				$(CC) $(CFLAGS) -c QueueNode.cc

Data.o: Data.cc Data.h
				$(CC) $(CFLAGS) -c Data.cc

clean:
	rm -f *.o *~