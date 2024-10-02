SRC = main.c q1.c q2.c q3.c
OBJ = $(SRC:.c=.o)
BIN = main

CFLAGS += -Wall -Wextra -g

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	rm -f *~

indent:
	indent -linux -i4 -nut -ts2 *.c

.PHONY: all clean indent