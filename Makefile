doink: main.o editor.o
	gcc -o bin/doink main.o editor.o -lncurses

main.o: 
editor.o: 

lint:
	astyle --style=java --suffix=none main.c
	cppcheck .

clean:
	rm *.o bin/doink
