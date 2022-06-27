#Objects (.o files)
OBJS = tokenizer.o history.o
OBJS_MAIN = $(OBJS) uimain.o

#Flag
CFLAGS=-g -O3

#dependencies
tokenizer.h :tokenizer.o uimain.o
history.h: uimain.o history.o tokenizer.o

tokenizer: $(OBJS_MAIN)
	cc -o tokenizer $(CFLAGS) $(OBJS_MAIN)

all: tokenizer

clean:
	rm -f *.o src

run:tokenizer
	./tokenizer
