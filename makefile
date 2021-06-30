calc: lex.yy.c y.tab.c
	gcc -g lex.yy.c y.tab.c matrix_op.c  print_file.c -o calc

lex.yy.c: y.tab.c test.l
	lex test.l

y.tab.c: test.y
	yacc -d test.y

clean: 
	rm -rf lex.yy.c y.tab.c y.tab.h calc calc.dSYM

