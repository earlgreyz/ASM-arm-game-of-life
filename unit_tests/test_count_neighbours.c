#include <stdio.h>
#include <assert.h>
#include "unit_tests.h"
#include "game_private.h"

#define sqr(a) (a*a)

#define size_4x4 6
#define size_1x1 3

static cell_t map[sqr(size_4x4)] = {
  0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 0, 0,
  0, 1, 1, 0, 1, 0,
  0, 0, 0, 0, 0, 0,
};

static void test_count_neighbours_4x4(void) {
  start(size_4x4, size_4x4, map);
  assert(_count_neighbours(2, 2) == 8);
  assert(_count_neighbours(2, 3) == 7);
  assert(_count_neighbours(3, 2) == 6);
  assert(_count_neighbours(1, 2) == 5);
  assert(_count_neighbours(2, 4) == 4);
  assert(_count_neighbours(4, 3) == 3);
  assert(_count_neighbours(4, 4) == 1);
}

static cell_t map_1x1[sqr(size_1x1)] = {
  0, 0, 0,
  0, 1, 0,
  0, 0, 0,
};

static void test_count_neighbours_1x1(void) {
  start(size_1x1, size_1x1, map_1x1);
  assert(_count_neighbours(1, 1) == 0);
}

void test_count_neighbours(void) {
  printf("\n");
  printf(" - 4x4 map... ");
  test_count_neighbours_4x4();
  printf("OK\n");
  printf(" - 1x1 map... ");
  test_count_neighbours_1x1();
  printf("OK\n");
  printf(" - All... ");
}
