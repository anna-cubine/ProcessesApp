#Define C compiler to run
CC=gcc

#Define compile-time flags
CFLAGS=-Wall -g

TARGET=processes

all: $(TARGET)

$(TARGET): $(TARGET).c
		$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c