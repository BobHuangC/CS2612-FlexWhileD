OUTPUT_DIR = bin
TARGET = $(OUTPUT_DIR)/flexWhileD

bin/flexWhileD: PreProcess/input.cpp
	g++ PreProcess/input.cpp -o PreProcess/input

LangAnalysis/lexer.h: LangAnalysis/lang.l
	flex LangAnalysis/lang.l

LangAnalysis/lexer.c: LangAnalysis/lang.l
	flex LangAnalysis/lang.l

LangAnalysis/parser.c: LangAnalysis/lang.y
	bison -o LangAnalysis/parser.c -d -v LangAnalysis/lang.y

LangAnalysis/parser.h: LangAnalysis/lang.y
	bison -o LangAnalysis/parser.c -d -v LangAnalysis/lang.y

LangAnalysis/lang.o: LangAnalysis/lang.c LangAnalysis/lang.h
	gcc -c LangAnalysis/lang.c

LangAnalysis/parser.o: LangAnalysis/parser.c LangAnalysis/parser.h LangAnalysis/lexer.h LangAnalysis/lang.h
	gcc -c LangAnalysis/parser.c

LangAnalysis/lexer.o: LangAnalysis/lexer.c LangAnalysis/lexer.h LangAnalysis/parser.h LangAnalysis/lang.h
	gcc -c LangAnalysis/lexer.c

LangAnalysis/main.o: LangAnalysis/main.c LangAnalysis/lexer.h LangAnalysis/parser.h LangAnalysis/lang.h
	gcc -c LangAnalysis/main.c

LangAnalysis/main: LangAnalysis/lang.o LangAnalysis/parser.o LangAnalysis/lexer.o LangAnalysis/main.o
	gcc LangAnalysis/lang.o LangAnalysis/parser.o LangAnalysis/lexer.o LangAnalysis/main.o -o LangAnalysis/main

all: $(TARGET)

clean:
	rm -f lexer.h lexer.c parser.h parser.c *.o main

%.c: %.y

%.c: %.l

.DEFAULT_GOAL := all