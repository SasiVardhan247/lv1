tinyc:par.o lex.o symbol.o ast.o
	g++ -o tinyc par.o lex.o  symbol.o ast.o -ll
ast.o:ast.cpp
	g++ -c ast.cpp -o ast.o
symbol.o:symboltable.cpp
	g++ -c symboltable.cpp -o symbol.o
par.o:y.tab.c
	g++ -c y.tab.c -o par.o
y.tab.c y.tab.h:tinyl1.y ast.hh
	yacc -d tinyl1.y
lex.o:lex.yy.c
	g++ -c lex.yy.c -o lex.o
lex.yy.c:tinyl1.l symboltable.hh
	lex tinyl1.l

