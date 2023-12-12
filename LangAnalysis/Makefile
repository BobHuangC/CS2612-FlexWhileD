lexer.h: lang.l
	flex lang.l

lexer.c: lang.l
	flex lang.l

parser.c: lang.y
	bison -o parser.c -d -v lang.y

parser.h: lang.y
	bison -o parser.c -d -v lang.y

lang.o: lang.c lang.h
	gcc -c lang.c

parser.o: parser.c parser.h lexer.h lang.h
	gcc -c parser.c

lexer.o: lexer.c lexer.h parser.h lang.h
	gcc -c lexer.c

analysis.o: analysis.c analysis.h parser.h lexer.h lang.h
	gcc -c analysis.c

main.o: main.c lexer.h parser.h lang.h analysis.h
	gcc -c main.c

LAtest2.o: LAtest2.cpp lexer.h parser.h lang.h analysis.h
	g++ -c LAtest2.cpp

main: lang.o parser.o lexer.o analysis.o main.o
	gcc lang.o parser.o lexer.o analysis.o main.o -o main

LAtest2: lang.o parser.o lexer.o analysis.o LAtest2.o sample_src02.jtl
	g++ lang.o parser.o lexer.o analysis.o LAtest2.o -o LAtest2

all: LAtest2

clean:
	rm -f lexer.h lexer.c parser.h parser.c *.o main

%.c: %.y

%.c: %.l

.DEFAULT_GOAL := all