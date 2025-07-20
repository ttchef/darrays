
CC = gcc
CFLAGS = -g

SRC_FILES = $(wildcard src/*.c) 
OBJ_FILES = $(SRC_FILES:.c=.o)

all: lib/libdarray.a

lib/libdarray.a: $(OBJ_FILES)
	mkdir -p lib 
	ar cr lib/libdarray.a $(OBJ_FILES)
	rm -f $(OBJ_FILES)

%.o: %.c 
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf lib $(OBJ_FILES)

install: lib/libdarray
	cp lib/libdarray.a /usr/local/lib/ 
	cp -r include/darray /usr/local/include/ 

uninstall:
	rm -rf /usr/local/lib/libleif.a 
	rm -rf /usr/local/include/darray/

example: lib/libdarray.a install
	$(CC) $(CFLAGS) example.c -o main -l:libdarray.a

.PHONY: all clean install uninstall 

