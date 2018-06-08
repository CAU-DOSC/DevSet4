CC = g++
CFLAGS = -Wall -std=c++11

OBJS = intsetarr.o intsetbins.o intsetbitvec.o intsetbst.o intsetlist.o
TARGET = test

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) test.cpp $(OBJS)

intsetarr:
	$(CC) $(CFLAGS) -c -o $(@).o $(@).cpp

intsetbins:
	$(CC) $(CFLAGS) -c -o $(@).o $(@).cpp

intsetbitvec:
	$(CC) $(CFLAGS) -c -o $(@).o $(@).cpp

intsetbst:
	$(CC) $(CFLAGS) -c -o $(@).o $(@).cpp

intsetlist:
	$(CC) $(CFLAGS) -c -o $(@).o $(@).cpp
