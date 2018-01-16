
.global start
.global run

@@ Functions exported for tests
.global _map_get
.global _count_neighbours
.global _prepare_neighbours_map
.global _apply_neighbours_map

/**
 * Extracts cell state from the cell.
 * @param dst: destination register
 * @param value: cell value
 **/
.macro cell_state dst, value
  and \dst, \value, #1
.endm

/**
 * Checks loop condition.
 * @param counter: register
 * @param cond: value to check condition on
 * @param label: label begining of the loop
 **/
.macro check_loop counter, cond, label
  sub \counter, #1
  cmp \counter, \cond
  bge \label
.endm

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

/**
 * Gets the pointer to the requested map cell.
 * @param x
 * @param y
 * @returns pointer to map[x][y]
 **/
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

/**
 * Counts the number of alive cell neighbours
 * @param x
 * @param y
 * @returns number of neighbours
 **/
_count_neighbours:
  push {r4, r5, r6, r7, r8, lr}

  mov r4, r0            @ save original x
  mov r5, r1            @ save original y
  eor r8, r8            @ neighbours_count = 0
  bl _map_get           @ current_cell = _map_get(x, y)

  @ neighbours_count -= state(*current_cell)
  ldr r0, [r0]
  cell_state r0, r0
  sub r8, r0

  @ Loops
  mov r7, #1            @ y_counter = 1
_count_loop_y:
  mov r6, #1            @ x_counter = 1
_count_loop_x:
  @ x = x + x_counter
  mov r0, r4
  add r0, r6
  @ y = y + y_counter
  mov r1, r5
  add r1, r7
  @ neighbour = _map_get(x, y)
  bl _map_get
  @ neighbours_count += state(*neighbour)
  ldr r0, [r0]
  cell_state r0, r0
  add r8, r0

_count_loop_end:
  eor r0, r0
  sub r0, #1
  check_loop r6, r0, _count_loop_x
  check_loop r7, r0, _count_loop_y
_count_neighbours_end:
  mov r0, r8
  pop {r4, r5, r6, r7, r8, lr}
  bx lr

/**
 * Calculate neighbours count for all cells on the map.
 * @returns void
 **/
_prepare_neighbours_map:
  bx lr

/**
 * Apply cell state based on its neighbours count, such that:
 * - cells with exactly ALIVE_COND neighbours become/remain ALIVE
 * - all other cells become DEAD
 **/
_apply_neighbours_map:
  bx lr

/**
 * Runs the simulation on the previously prepared map.
 * @param steps number of times to run the simulation for.
 **/
run:
  bx lr

@ Labels for accessing variables
width:  .word width_var
height: .word height_var
map:    .word map_var
