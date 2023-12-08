input: PreProcess/input.cpp
	g++ PreProcess/input.cpp -o input

LangAnalysis/lexer.h: LangAnalysis/lang.l
	flex LangAnalysis/lang.l

LangAnalysis/lexer.c: LangAnalysis/lang.l
	flex LangAnalysis/lang.l

LangAnalysis/parser.c: LangAnalysis/lang.y
	bison -o LangAnalysis/parser.c -d -v LangAnalysis/lang.y

LangAnalysis/parser.h: LangAnalysis/lang.y
	bison -o LangAnalysis/parser.c -d -v LangAnalysis/lang.y

LangAnalysis/lib.o: LangAnalysis/lib.c LangAnalysis/lib.h
	gcc -c LangAnalysis/lib.c

LangAnalysis/lang.o: LangAnalysis/lang.c LangAnalysis/lang.h LangAnalysis/lib.h
	gcc -c LangAnalysis/lang.c

LangAnalysis/parser.o: LangAnalysis/parser.c LangAnalysis/parser.h LangAnalysis/lexer.h LangAnalysis/lang.h
	gcc -c LangAnalysis/parser.c

LangAnalysis/lexer.o: LangAnalysis/lexer.c LangAnalysis/lexer.h LangAnalysis/parser.h LangAnalysis/lang.h
	gcc -c LangAnalysis/lexer.c

LangAnalysis/main.o: LangAnalysis/main.c LangAnalysis/lexer.h LangAnalysis/parser.h LangAnalysis/lang.h
	gcc -c LangAnalysis/main.c

LangAnalysis/main: LangAnalysis/lang.o LangAnalysis/parser.o LangAnalysis/lexer.o LangAnalysis/lib.o LangAnalysis/main.o
	gcc LangAnalysis/lang.o LangAnalysis/parser.o LangAnalysis/lexer.o LangAnalysis/lib.o LangAnalysis/main.o -o LangAnalysis/main

all: LangAnalysis/main

clean:
	rm -f LangAnalysis/lexer.h LangAnalysis/lexer.c LangAnalysis/parser.h LangAnalysis/parser.c *.o LangAnalysis/main

%.c: %.y

%.c: %.l

.DEFAULT_GOAL := all

