CC=g++
CFLAGS=-c -Wall -std=c++98 
LDFLAGS=
SOURCES=BTNode.h BSTree.h MechPart.cpp HTable.h TreeHashTableDemo-1.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a3

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
