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

main.o: main.cpp PreProcess/input.h NFADFA/DFA.h NFADFA/NFA.h
	g++ -c main.cpp

lang_test.o: lang_test.cpp PreProcess/input.h NFADFA/DFA.h NFADFA/NFA.h
	g++ -c lang_test.cpp

# input: PreProcess/input.cpp lang.o parser.o lexer.o analysis.o
# 	g++ PreProcess/input.cpp lang.o parser.o lexer.o analysis.o -o bin/input

INtest: lang.o parser.o lexer.o analysis.o INtest.o input.o
	g++ lang.o parser.o lexer.o analysis.o INtest.o input.o -o bin/INtest

LAtest2: lang.o parser.o lexer.o analysis.o LAtest2.o
	g++ lang.o parser.o lexer.o analysis.o LAtest2.o -o bin/LAtest2

DFAtest: DFAtest.o DFA.o NFA.o RE.o lang.o parser.o lexer.o analysis.o input.o
	g++ DFAtest.o DFA.o NFA.o RE.o lang.o parser.o lexer.o analysis.o input.o -o bin/DFAtest

main: main.o DFA.o NFA.o RE.o lang.o parser.o lexer.o analysis.o input.o
	g++ main.o DFA.o NFA.o RE.o lang.o parser.o lexer.o analysis.o input.o -o bin/flexWhileD

lang_test: lang_test.o DFA.o NFA.o RE.o lang.o parser.o lexer.o analysis.o input.o
	g++ lang_test.o DFA.o NFA.o RE.o lang.o parser.o lexer.o analysis.o input.o -o bin/lang_test

flexWhileD: main.o DFA.o NFA.o RE.o lang.o parser.o lexer.o analysis.o input.o
	g++ main.o DFA.o NFA.o RE.o lang.o parser.o lexer.o analysis.o input.o -o bin/flexWhileD

clean:
	rm -f parser.output lexer.h lexer.c parser.h parser.c *.o main

%.c: %.y

%.c: %.l

.DEFAULT_GOAL := main