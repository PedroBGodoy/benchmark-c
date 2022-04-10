CC=gcc
BINS=benchmark.so libtest
all: $(BINS)

benchmark.o:
	$(CC) -c benchmark.c

build-shared: benchmark.o
	$(CC) -fPIC -shared -o benchmark.so benchmark.o

libtest: libtest.c benchmark.o
	$(CC) -o $@ $^

clean: 
	rm *.o $(BINS)