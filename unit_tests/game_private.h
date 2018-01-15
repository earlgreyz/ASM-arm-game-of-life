#ifndef GAME_PRIVATE_H
#define GAME_PRIVATE_H

#include "../game.h"

#define map_get(map, w, x, y) (map + w * (y) + (x))

extern cell_t *_map_get(size_t x, size_t y);
extern size_t _count_neighbours(size_t x, size_t y);
extern void _prepare_neighbours_map(void);
extern void _apply_neighbours_map(void);

#endif
