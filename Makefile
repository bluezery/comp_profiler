all: exe

exe: prof.c lib
	gcc -Wall -pg -fno-omit-frame-pointer -g -ggdb -o prof prof.c -lprof -L./

lib: libprof.c
	gcc -Wall -shared -pg  -fno-omit-frame-pointer -g -ggdb -o libprof.so libprof.c

clean:
	rm -rf prof libprof.so

.PHONY: clean lib exe
