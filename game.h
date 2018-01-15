#ifndef GAME_H
#define GAME_H

typedef int cell_t;

/**
 * Prepares the simulation.
 * @param width width of the map.
 * @param height height of the map.
 * @param T map of the cells state 0.
 **/
extern void start(size_t width, size_t height, cell_t *map);

/**
 * Runs the simulation on the previously prepared map.
 * @param steps numer of times to run the simulation for.
 **/
extern void run(int steps);

#endif
