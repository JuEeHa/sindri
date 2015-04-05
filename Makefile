CFLAGS = -Os -pipe -std=c11 -pedantic -Wall -Wextra
CPPFLAGS = -I.
LDFLAGS = -L.

LIBOBJ = allocation.o gc.o parse.o types.o
REPLOBJ = repl.o

all: sindri libsindri.a

sindri: $(REPLOBJ) libsindri.a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $(REPLOBJ) -lsindri

libsindri.a: $(LIBOBJ)
	rm -f $@
	ar -r $@ $(LIBOBJ)

allocation.o: sindri.h types.h

gc.o: sindri.h

parse.o: sindri.h

repl.o: sindri.h

types.o: sindri.h

.SUFFIXES:
.SUFFIXES: .o .c

.c.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f *.o *.a sindri

.PHONY: all clean
