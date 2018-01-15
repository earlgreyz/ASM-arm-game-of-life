#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "unit_tests.h"

char *test_names[TESTS_COUNT] = {
  "map_get",
  "count_neighbours",
  "prepare_neighbours_map",
  "apply_neighbours_map",
  "run",
};

void (*test_functions[TESTS_COUNT])(void) = {
  &test_map_get,
  &test_count_neighbours,
  &test_prepare_neighbours_map,
  &test_apply_neighbours_map,
  &test_run,
};


bool shall_test_all = false;

bool shall_test(char *test_name, int argc, char *argv[]) {
  if (shall_test_all) {
    return true;
  }

  for (size_t i = 1; i < argc; i++) {
    if (strcmp(argv[1], test_name) == 0) {
      return true;
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  if (argc == 1 || strcmp(argv[1], "all") == 0) {
    shall_test_all = true;
  }

  for (size_t i = 0; i < TESTS_COUNT; i++) {
    if (shall_test(test_names[i], argc, argv)) {
      printf("Running `%s`... ", test_names[i]);
      test_functions[i]();
      printf("OK\n");
    }
  }
  return 0;
}
