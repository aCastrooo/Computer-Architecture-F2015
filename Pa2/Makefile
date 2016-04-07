CC = gcc
CFLAGS = -g -DRPC_SVC_FG

all: count

count: count.o 
	$(CC) -o count count.o -lnsl

clean:
	rm -f count count.o 

