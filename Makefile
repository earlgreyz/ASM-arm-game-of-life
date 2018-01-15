game: game.c game.o
	gcc -std=c99 -o game -Wall -O2 game.c game.o

.SECONDARY:
%.o: %.s
	as -o $@ $<

.PHONY: clean
clean:
	rm -f *.o game
