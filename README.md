# push_swap

Sort a stack of integers using a limited set of operations, with the fewest moves possible.

---

## Algorithm

The project uses the **Turkish sort** (minimum-cost insertion) for large inputs:

1. **Push to B** -- Elements are pushed from A to B by always picking the cheapest element to move. B is kept sorted in descending order (circular). Cost = rotations on A + rotations on B, with `rr`/`rrr` optimization when both stacks rotate in the same direction.
2. **Sort the last 3** -- The 3 remaining elements in A are sorted with `sort_3`.
3. **Push back to A** -- Each element from B is pushed back to A (largest to smallest), rotating A to the correct insertion position.
4. **Final rotation** -- A is rotated to bring the minimum to the top.

For 5 elements or fewer, dedicated algorithms (`sort_2`, `sort_3`, `sort_4`, `sort_5`) are used.

An optimization pass merges redundant operations (`ra`+`rb` -> `rr`, cancellation of pairs like `ra`+`rra`, etc.).

---

## Performance

Benchmark over 100 random runs per size:

| Size | Avg ops | Max ops | 42 threshold |
|------|---------|---------|--------------|
| 3    | 1       | 2       | 3            |
| 5    | 6       | 10      | 12           |
| 100  | 559     | 650     | 700          |
| 500  | 5107    | 5419    | 5500         |

---

## Compilation

```bash
make        # compile push_swap
make bonus  # compile the checker
make re     # full recompilation
make clean  # remove .o files
make fclean # remove .o files and binaries
```

---

## Usage

```bash
./push_swap 4 2 6 3 1 5
```

Prints the list of operations to stdout, one per line.

### Checker (bonus)

Reads operations from stdin and verifies that the stack is sorted:

```bash
./push_swap 4 2 6 3 1 5 | ./checker 4 2 6 3 1 5
# OK
```

---

## Operations

| Op    | Effect                                          |
|-------|-------------------------------------------------|
| `sa`  | Swap the two top elements of A                  |
| `sb`  | Swap the two top elements of B                  |
| `ss`  | `sa` + `sb`                                     |
| `pa`  | Push the top of B onto A                        |
| `pb`  | Push the top of A onto B                        |
| `ra`  | Rotate A upward (top goes to bottom)            |
| `rb`  | Rotate B upward                                 |
| `rr`  | `ra` + `rb`                                     |
| `rra` | Reverse rotate A (bottom goes to top)           |
| `rrb` | Reverse rotate B                                |
| `rrr` | `rra` + `rrb`                                   |

---

## Structures

| Struct    | Role                                                  |
|-----------|-------------------------------------------------------|
| `t_stack` | Dynamic stack (array of `t_elem`: value + index)      |
| `t_ops`   | Dynamic array of operations (strings)                 |
| `t_cost`  | Cost of a move (cost_a, cost_b, total)                |

---

## Project structure

```
push_swap.h        Header (structs, prototypes)
main.c             Entry point, dispatch to sorting
turk_sort.c        Turkish sort orchestration
turk_cost.c        Cost computation, target position in B
turk_exec.c        Move execution with rr/rrr optimization
sort_small.c       Dedicated sorts for 2-5 elements
sort_utils.c       Helpers (min_pos, rotate_to_top, push_max)
ops.c              Stack operations (swap, push, rotate, revrotate)
ops_utils.c        Operation list management
optimize_ops.c     Post-sort operation merging/cancellation
parsing.c          Argument parsing
parsing_utils.c    Validation, error handling
indexing.c         Value -> rank indexing
checker.c          Bonus: operation verifier
```
