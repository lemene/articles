RE2C=..\re2c
CC=gcc
RM=del

BIN=$(ID).exe
RE2C_FILE = $(ID).re
GEN_FILE = $(ID).c

$(BIN): main.o
	$(CC) -o $@ $^

main.o: main.c $(GEN_FILE)
	$(CC) -c main.c -std=c99

$(GEN_FILE): $(RE2C_FILE)
	$(RE2C) $< -o $@

clean:
	$(RM) $(GEN_FILE) main.o $(BIN)

