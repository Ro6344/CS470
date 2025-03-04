# Variables
CC = gcc
CFLAGS = -Wall -g
SRC = SJF_Initial.c RR_Initial.c
OBJ = $(SRC:.c=.o)

# Targets
all: SJF_Initial RR_Initial

SJF_Initial: SJF_Initial.o
	$(CC) $(CFLAGS) -o SJF_Initial SJF_Initial.o

RR_Initial: RR_Initial.o
	$(CC) $(CFLAGS) -o RR_Initial RR_Initial.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) SJF_Initial RR_Initial


