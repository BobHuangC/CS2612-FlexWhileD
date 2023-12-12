lexer1.h: LangAnalysis/lang.l
	flex -o LangAnalysis//lexer1.h LangAnalysis/lang.l

lexer1.c: LangAnalysis/lang.l
	flex -o LangAnalysis//lexer1.c LangAnalysis/lang.l

parser.c: lang.y
	bison -o parser.c -d -v lang.y

input: PreProcess/input.cpp LangAnalysis/lang.o LangAnalysis/parser.o LangAnalysis/lexer.o LangAnalysis/analysis.o
	g++ PreProcess/input.cpp LangAnalysis/lang.o LangAnalysis/parser.o LangAnalysis/lexer.o LangAnalysis/analysis.o -o input

clean:
	rm -f lexer.h lexer.c parser.h parser.c *.o main

%.c: %.y

%.c: %.l

.DEFAULT_GOAL := all