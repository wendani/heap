AM_CFLAGS := -g -Wall -O2

CC        := g++
CFLAGS    := $(AM_CFLAGS)

LD        := g++

APPS      := heap
OBJS      := $(APPS).o
SRCS      := $(APPS).c

heap: heap.o
	$(LD) $(AM_CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(APPS) *.o *.out
