LEMON=..\lemon
CC=gcc          # 使用CL需要用/Fo和/Fe替代-

BIN=arith.exe
RM=del

$(BIN): main.o
	$(CC) $^ -o $(BIN)

main.o: main.c arith.c arith.h
	$(CC) -c $< -o $@

arith.h arith.c: arith.y
	$(LEMON) $<

clean:
	$(RM) main.o $(BIN) arith.c arith.h arith.out
