#include <stdio.h>
#include <assert.h>
#include "unit_tests.h"
#include "game_private.h"

#define width 4
#define height 4

static cell_t map[(width * height)] = {
  0, 0, 0, 0,
  0, 1, 0, 0,
  0, 1, 1, 0,
  0, 0, 0, 0
};

static void test_pointers(void) {
  for (size_t y = 1; y < height - 1; y++) {
    for (size_t x = 1; x < width - 1; x++) {
      assert(map_get(map, width, x, y) == _map_get(x, y));
    }
  }
}

static void test_values(void) {
  assert(*_map_get(0, 0) == 0);
  assert(*_map_get(1, 1) == 1);
  assert(*_map_get(2, 1) == 0);
  assert(*_map_get(1, 2) == 1);
}

void test_map_get(void) {
  start(width, height, map);
  test_pointers();
  test_values();
}
