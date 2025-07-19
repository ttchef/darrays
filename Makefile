
CC := gcc
CFLAGS := -O2 -Wall -Iinclude

# For static lib
AR := ar 
ARFLAGS := rcs

SRC := $(wildcard src/*.c) 
OBJ := $(SRC:.c=.o)

LIB := lib/darrays.a
TEST := test/main

all: $(LIB) $(TEST)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST): $(LIB) test/main.c
	$(CC) $(CFLAGS) test/main.c -Llib -ldarray -o $(TEST)

clean:
	rm -f src/*.o $(LIB) $(TEST)

