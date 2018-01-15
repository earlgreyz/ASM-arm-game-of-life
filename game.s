
.global start
.global run

@@ Functions exported for tests
.global _map_get
.global _count_neighbours
.global _prepare_neighbours_map
.global _apply_neighbours_map

.data
.balign 4
  width_var:  .int 0   @ size_t width
.balign 4
  height_var: .int 0   @ size_t height
.balign 4
  map_var:    .word 0  @ cell_t *map

.text

.balign 4
start:
  ldr r3, width
  str r0, [r3]
  ldr r3, height
  str r1, [r3]
  ldr r3, map
  str r2, [r3]
  bx lr

/* Gets the pointer to the requested map cell.
 * @param x
 * @param y
 * @returns pointer to map[x][y] */
_map_get:
  ldr r2, width
  ldr r2, [r2]        @ offset = width
  mul r2, r1          @ offset *= y
  add r2, r0          @ offset += x
  lsl r2, #2          @ offset *= 4
  @ cell_ptr = map + 4 * (width * y + x)
  ldr r3, map
  ldr r3, [r3]
  add r0, r3, r2
  bx lr

/* Counts the number of alive cell neighbours
 * @param x (rdi)
 * @param y (rsi)
 * @returns void */
_count_neighbours:
  bx lr

/* Calculate neighbours count for all cells on the map */
_prepare_neighbours_map:
  bx lr

/* Apply cell state based on its neighbours count, such that:
 * - cells with exactly ALIVE_COND neighbours become/remain ALIVE
 * - all other cells become DEAD */
_apply_neighbours_map:
  bx lr

/* Runs the simulation on the previously prepared map.
 * @param steps number of times to run the simulation for. */
run:
  bx lr

@ Labels for accessing variables
width:  .word width_var
height: .word height_var
map:    .word map_var
