lexer.h: LangAnalysis/lang.l
	flex LangAnalysis/lang.l

lexer.c: LangAnalysis/lang.l
	flex LangAnalysis/lang.l

parser.c: LangAnalysis/lang.y
	bison -o parser.c -d -v LangAnalysis/lang.y

parser.h: LangAnalysis/lang.y
	bison -o parser.c -d -v LangAnalysis/lang.y

lang.o: LangAnalysis/lang.c LangAnalysis/lang.h
	gcc -c LangAnalysis/lang.c

parser.o: parser.c parser.h lexer.h LangAnalysis/lang.h
	gcc -c parser.c

lexer.o: lexer.c lexer.h parser.h LangAnalysis/lang.h
	gcc -c lexer.c

analysis.o: LangAnalysis/analysis.c LangAnalysis/analysis.h parser.h lexer.h LangAnalysis/lang.h
	gcc -c LangAnalysis/analysis.c

input.o: PreProcess/input.cpp LangAnalysis/lang.h parser.h lexer.h LangAnalysis/analysis.h
	g++ -c PreProcess/input.cpp

RE.o: NFADFA/RE.cpp
	g++ -c NFADFA/RE.cpp

NFA.o: NFADFA/NFA.cpp RE.o
	g++ -c NFADFA/NFA.cpp

DFA.o: NFADFA/DFA.cpp NFA.o
	g++ -c NFADFA/DFA.cpp

INtest.o: test/INtest.cpp LangAnalysis/lang.h parser.h lexer.h LangAnalysis/analysis.h
	g++ -c test/INtest.cpp

LAtest2.o: test/LAtest2.cpp lexer.h parser.h LangAnalysis/lang.h LangAnalysis/analysis.h
	g++ -c test/LAtest2.cpp

DFAtest.o: test/DFAtest.cpp PreProcess/input.h NFADFA/DFA.h NFADFA/NFA.h
	g++ -c test/DFAtest.cpp

INtest: lang.o parser.o lexer.o analysis.o INtest.o input.o
	g++ lang.o parser.o lexer.o analysis.o INtest.o input.o -o INtest

LAtest2: lang.o parser.o lexer.o analysis.o LAtest2.o
	g++ lang.o parser.o lexer.o analysis.o LAtest2.o -o LAtest2

DFAtest: DFAtest.o DFA.o NFA.o RE.o lang.o parser.o lexer.o analysis.o input.o
	g++ DFAtest.o DFA.o NFA.o RE.o lang.o parser.o lexer.o analysis.o input.o -o DFAtest

main.o: main.c lexer.h parser.h lang.h analysis.h
	gcc -c main.c

main: lang.o parser.o lexer.o analysis.o main.o
	gcc lang.o parser.o lexer.o analysis.o main.o -o main

input: PreProcess/input.cpp LangAnalysis/lang.o LangAnalysis/parser.o LangAnalysis/lexer.o LangAnalysis/analysis.o
	g++ PreProcess/input.cpp LangAnalysis/lang.o LangAnalysis/parser.o LangAnalysis/lexer.o LangAnalysis/analysis.o -o input

clean:
	rm -f parser.output lexer.h lexer.c parser.h parser.c *.o main

%.c: %.y

%.c: %.l

.DEFAULT_GOAL := all