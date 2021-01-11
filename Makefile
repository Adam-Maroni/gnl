CC = gcc
FLAGS = -Wall -Werror -Wextra
BUFFER_SIZE = 32
SRC = get_next_line.c get_next_line_utils.c
OUT = gnl.out

normal:
	$(CC) $(FLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC) -o $(OUT)

main:
	$(CC) $(FLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC) main.c -o $(OUT)

lldb:
	$(CC) $(FLAGS) -g -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC) main.c -o $(OUT)
	lldb $(OUT)

memcheck:
	$(CC) $(FLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -fsanitize=address $(SRC) main.c -o $(OUT)
	./$(OUT)
