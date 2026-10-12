CFLAGS=-g -O0

all:tokenizer

tokenizer.o:tokenizer.h
history.o:history.h tokenizer.h
main.o: tokenizer.h history.h

tokenizer: main.o tokenizer.o history.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizer
