CC=gcc
CFLAGS=-lpthread -lopenblas
MOREFLAGS=-std=c99 -pedantic -Wall -Wshadow -Wpointer-arith -Wcast-qual

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(MOREFLAGS) -o $(@) $(<)

clean:
	rm -f $(PROGS)
