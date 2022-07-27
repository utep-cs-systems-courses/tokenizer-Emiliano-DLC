#Flag
CFLAGS=-g -O3

#dependencies
tokenizer.o: tokenizer.h
uimain.o: tokenizer.h
history.o: history.c

uimain: tokenizer.o history.o uimain.o
	cc -o $@ $^ $(CFLAGS)

all: uimain

clean:
	rm -f *.o *.c~ *.h~ *~ *.c# *.h# src

run:uimain
	./uimain
