all:
	gcc -c memory.c -o memory.o
	gcc -c lexer.c -o lexer.o
	gcc -c parser.c -o parser.o
	gcc -c whale.c -o whale.o
	gcc whale.o lexer.o parser.o memory.o -o whale

clean:
	-rm *.o whale

