CC = g++
CFLAGS = -Wall -std=c++11

HASH = MurmurHash2.o

OBJS = intsetarr.o intsetbins.o intsetbitvec.o intsetbst.o intsetlist.o $(HASH)
TARGET = test

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS) $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) test.cpp $(OBJS)

intsetarr.o:
	$(CC) $(CFLAGS) -c $(*).cpp

intsetbins.o:
	$(CC) $(CFLAGS) -c $(*).cpp

intsetbitvec.o:
	$(CC) $(CFLAGS) -c $(*).cpp

intsetbst.o:
	$(CC) $(CFLAGS) -c $(*).cpp

intsetlist.o:
	$(CC) $(CFLAGS) -c $(*).cpp

$(HASH):
	$(CC) $(CFLAGS) -c $(*).cpp
