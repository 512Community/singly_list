CC = gcc

OBJ = $(patsubst %.c, %.o, $(wildcard *.c))
LIB =
INCLUDE = -I./
CFLAGS = -Werror -g

target = main 

all: $(OBJ)
	$(CC) $^ -o $(target) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf *.o $(target)
