CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC =  adt/charmachine.c adt/datetime.c adt/graph.c adt/kicauan.c adt/matrix.c adt/pcolor.c adt/pengguna.c adt/pertemanan.c adt/prioqueue.c adt/queue.c adt/stack.c adt/teman.c adt/time.c adt/utas.c adt/wordmachine.c adt/balasan.c adt/draftkicauan.c main.c feat/io.c feat/misc.c feat/operational.c

TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
