#include <stdio.h>
#include <assert.h>
#include "unit_tests.h"
#include "game_private.h"

#define sqr(a) (a*a)

#define size_1x1 3
#define size_2x2 4
#define size_4x4 6

static cell_t map[sqr(size_4x4)] = {
  0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 0, 0,
  0, 1, 1, 0, 1, 0,
  0, 0, 0, 0, 0, 0,
};

static size_t neighbours[sqr(size_4x4)] = {
  0, 0, 0, 0, 0, 0,
  0, 3, 5, 4, 2, 0,
  0, 5, 8, 6, 4, 0,
  0, 5, 7, 5, 3, 0,
  0, 3, 4, 4, 1, 0,
  0, 0, 0, 0, 0, 0,
};

static void test_prepare_neighbours_map_4x4(void) {
  start(size_4x4, size_4x4, map);
  _prepare_neighbours_map();

  for (size_t y = 1; y < size_4x4 - 1; y++) {
    for (size_t x = 1; x < size_4x4 - 1; x++) {
      cell_t * cell = map_get(map, size_4x4, x, y);
      size_t neighbours_count = (*cell) >> 8;
      assert(neighbours_count == *map_get(neighbours, size_4x4, x, y));
    }
  }
}

static cell_t map_1x1[sqr(size_1x1)] = {
  0, 0, 0,
  0, 1, 0,
  0, 0, 0,
};
  
static void test_prepare_neighbours_map_1x1(void) {
  start(size_1x1, size_1x1, map_1x1);
  _prepare_neighbours_map();

  for (size_t y = 0; y <= size_1x1 - 1; y++) {
    for (size_t x = 0; x <= size_1x1 - 1; x++) {
      cell_t * cell = map_get(map_1x1, size_1x1, x, y);
      size_t neighbours_count = (*cell) >> 8;
      assert(neighbours_count == 0);
    }
  }
}

static cell_t map_2x2[sqr(size_2x2)] = {
  0, 0, 0, 0,
  0, 1, 1, 0,
  0, 1, 1, 0,
  0, 0, 0, 0,
};

static void test_prepare_neighbours_map_2x2(void) {
  start(size_2x2, size_2x2, map_2x2);
  _prepare_neighbours_map();

  for (size_t y = 0; y <= size_2x2 - 1; y++) {
    for (size_t x = 0; x <= size_2x2 - 1; x++) {
      cell_t * cell = map_get(map_2x2, size_2x2, x, y);
      if (y == 0 || y == size_2x2 -1 || x == 0 || x == size_2x2 -1) {
        assert(*cell == 0);
      } else {
        size_t neighbours_count = (*cell) >> 8;
        assert(neighbours_count == 3);
      }
    }
  }
}


void test_prepare_neighbours_map(void) {
  printf("\n");
  printf(" - 4x4 map... ");
  test_prepare_neighbours_map_4x4();
  printf("OK\n");
  printf(" - 1x1 map... ");
  test_prepare_neighbours_map_1x1();
  printf("OK\n");
  printf(" - 2x2 map... ");
  test_prepare_neighbours_map_2x2();
  printf("OK\n");
  printf(" - All... ");
}
