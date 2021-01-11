CC = gcc
FLAGS = -Wall -Werror -Wextra
BUFFER_SIZE = 32
SRC = get_next_line.c get_next_line_utils.c

all :
	$(CC) $(FLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC)
