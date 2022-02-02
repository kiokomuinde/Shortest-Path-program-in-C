# Define the machine object files for your program
OBJECTS = main.o Graph.o  Queue.o Stack.o
# Define your include file
INCLUDES = Graph.h Queue.h Stack.h

# make for the executable
p4: main.o Graph.o Queue.o Stack.o
	gcc -g -o p4 main.o Graph.o Queue.o Stack.o

# Simple suffix rules for the .o
main.o: main.c Graph.h
	gcc -g -c main.c

Graph.o: Graph.c Graph.h Queue.h Stack.h
	gcc -g -c Graph.c

Queue.o: Queue.c Queue.h
	gcc -g -c Queue.c

Stack.o: Stack.c Stack.h
	gcc -g -c Stack.c

# Clean the .o files
clean:
	rm -f *.o p4
