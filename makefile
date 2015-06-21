CC=g++

CFLAGS= 
LFLAGS=
SOURCES=simulate.cpp cupe.cpp toe.cpp processor.cpp
INCLUDES=cupe.h toe.h processor.h


all: simulate 

simulate: $(SOURCES) $(INCLUDES)
	$(CC) $(CFLAGS) $(SOURCES) -o simulate $(LFLAGS)

clean:
	rm -f simulate *~ *.o
