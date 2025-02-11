#define compiler
CC = gcc 

#define compiler flags 
CFLAGS = -Wall -Wextra -g 

#Target executable name 
TARGET = main

#source files 
SRCS = main.c

#object files 
OBJS = $(SRCS:.c=.o)

#default rule to build executable 
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

#rule to compile source files into object files
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

#clean rule to remove compiled files 
clean: 
	rm -f $(TARGET) $(OBJS) 