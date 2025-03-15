CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = Rocio_testFS

OBJS = Rocio_libFS.o Rocio_testFS.o
  
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

Rocio_libFS.o: Rocio_libFS.c Rocio_libFS.h
	$(CC) $(CFLAGS) -c Rocio_libFS.c

Rocio_testFS.o: Rocio_testFS.c Rocio_libFS.h
	$(CC) $(CFLAGS) -c Rocio_testFS.c

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)
