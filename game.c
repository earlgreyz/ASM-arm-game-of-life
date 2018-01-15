#include <stdio.h>
#include <stdlib.h>
#include "game.h"

#define DEAD_CELL  '.'
#define ALIVE_CELL '#'

#define map_get(x, y) (map + width * (y) + (x))

size_t width, height;
cell_t *map;

/**
 * Initializes map with guardians and values from STDIN.
 * @param width desired map width.
 * @param height desired map height.
 **/
void initialize_map(void) {
  // Increase width and height by 2 to provide "Guardians"
  width += 2;
  height += 2;
  map = (cell_t *) calloc(width * height, sizeof(cell_t));

  for (size_t y = 1; y < height - 1; y++) {
    for (size_t x = 1; x < width - 1; x++) {
      scanf("%d", map_get(x, y));
    }
  }
}

/**
 * Converts cell value to its char representation.
 * '.' - dead cell
 * '#' - alive cell
 * @returns cell representation.
 **/
char get_representation(cell_t cell) {
  return (cell & 0x01) == 0? DEAD_CELL: ALIVE_CELL;
}

/**
 * Prints map ASCII representation.
 **/
void print_map(void) {
  for (size_t y = 1; y < height - 1; y++) {
    for (size_t x = 1; x < width - 1; x++) {
      printf("%c", get_representation(*map_get(x, y)));
    }
    printf("\n");
  }
}

/**
 * Initialize program.
 **/
void init(void) {
  scanf(" %u %u", &width, &height);
  initialize_map();
  start(width, height, map);
}

/**
 * Free all alocated memory to avoid leaks.
 **/
void cleanup(void) {
  free(map);
}

/**
 * Runs the game.
 **/
void iterate(void) {
  size_t steps;
  while (scanf(" %u", &steps) != EOF) {
    run(steps);
    print_map();
  };
}

int main(int argc, char *argv[]) {
  init();
  iterate();
  cleanup();
  return 0;
}
