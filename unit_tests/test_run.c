#include <stdio.h>
#include <assert.h>
#include "unit_tests.h"
#include "game_private.h"

#define width 6
#define height 6

static cell_t map[(width * height)];

static cell_t map0[(width * height)] = {
  0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 0, 0,
  0, 1, 1, 0, 1, 0,
  0, 0, 0, 0, 0, 0,
};

static cell_t map1[(width * height)] = {
  0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 0,
  0, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0,
};

static void map_copy(cell_t *dest, cell_t *src) {
  for (size_t i = 0; i < width * height; i++) {
    dest[i] = src[i];
  }
}

static void test_step_0(void) {
  printf("  - Testing step = 0... ");
  map_copy(map, map0);
  start(width, height, map);
  run(0);
  for (size_t y = 1; y < height - 1; y++) {
    for (size_t x = 1; x < width - 1; x++) {
      assert(*map_get(map, width, x, y) == *map_get(map0, width, x, y));
    }
  }
  printf("OK.\n");
}

static void test_step_1(void) {
  printf("  - Testing step = 1... ");
  map_copy(map, map0);
  start(width, height, map);
  run(1);
  for (size_t y = 1; y < height - 1; y++) {
    for (size_t x = 1; x < width - 1; x++) {
      assert(*map_get(map, width, x, y) == *map_get(map1, width, x, y));
    }
  }
  run(1);
  for (size_t i = 0; i < width * height; i++) {
    assert(map[i] == 0);
  }
  printf("OK.\n");
}

static void test_step_2(void) {
  printf("  - Testing step = 2... ");
  map_copy(map, map0);
  start(width, height, map);
  run(2);
  for (size_t i = 0; i < width * height; i++) {
    assert(map[i] == 0);
  }
  printf("OK.\n");
}

void test_run(void) {
  printf("\n");
  test_step_0();
  test_step_1();
  test_step_2();
  printf("  - All... ");
}
