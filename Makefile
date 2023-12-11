input: PreProcess/input.cpp LangAnalysis/lang.o LangAnalysis/parser.o LangAnalysis/lexer.o LangAnalysis/analysis.o
	g++ PreProcess/input.cpp LangAnalysis/lang.o LangAnalysis/parser.o LangAnalysis/lexer.o LangAnalysis/analysis.o -o input

all: $(TARGET)

clean:
	rm -f lexer.h lexer.c parser.h parser.c *.o main

%.c: %.y

%.c: %.l

.DEFAULT_GOAL := all