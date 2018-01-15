TESTS = test_map_get.c test_count_neighbours.c test_prepare_neighbours_map.c test_apply_neighbours_map.c test_run.c

unit_tests: $(TESTS) unit_tests.c game.o
	gcc -std=c99 -o unit_tests unit_tests.c $(TESTS) game.o -Wall

.SECONDARY:
game.o: ../game.s
	as -o game.o $<

clean:
	rm -f *.o unit_tests
