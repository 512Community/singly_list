CC = gcc

OBJ = singly_list.o main.o
LIB = 
INCLUDE =  -I./
CFLAGS = -Werror -g

target = main 

all: $(OBJ) 
	$(CC) $^ -o $(target) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf *.o $(target)
