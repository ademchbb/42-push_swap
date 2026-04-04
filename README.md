*This project has been created as part of the 42 curriculum by adchebbi.*

# Push_swap

## Description

Push_swap is a sorting algorithm project where the goal is to sort a stack of integers using a limited set of operations, with the lowest possible number of moves. The program takes a list of integers as arguments, and outputs a sequence of instructions that sorts them in ascending order.

The project uses two stacks (a and b) and 11 allowed operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

### Algorithm: Cost-Based Approach

The sorting algorithm works in two phases:

**Phase 1 — Push from a to b:**
All elements except three are pushed from stack a to stack b. For each element in a, the algorithm calculates the cost (number of rotations) needed to place it in the correct position in b. The cheapest element is moved first. When both stacks need to rotate in the same direction, combined operations (`rr` or `rrr`) are used to save moves. Stack b is maintained in descending order.

**Phase 2 — Push back to a:**
The three remaining elements in a are sorted directly. Then, each element from b is pushed back into stack a at its correct position. Finally, stack a is rotated so that the smallest element is on top.

**Optimization — Indexing:**
Before sorting, each value is replaced by its rank (index from 0 to n-1). This simplifies comparisons and makes the algorithm independent of the actual values.

### Performance

| Stack size | Average operations | Benchmark target |
|------------|-------------------|-----------------|
| 100        | ~550-600          | < 700           |
| 500        | ~4900-5200        | ≤ 5500          |

## Instructions

### Compilation

```bash
make
```

### Usage

```bash
./push_swap 4 67 3 87 23
```

Arguments can also be passed as a single string:

```bash
./push_swap "4 67 3 87 23"
```

To count the number of operations:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

To verify the sort is correct (with the checker provided by 42):

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

To verify benchmarks (100 random numbers):

```bash
ARG=$(python3 -c "import random; nums = list(range(100)); random.shuffle(nums); print(' '.join(map(str, nums)))"); ./push_swap $ARG | wc -l
```

To verify benchmarks (500 random numbers):

```bash
ARG=$(python3 -c "import random; nums = list(range(500)); random.shuffle(nums); print(' '.join(map(str, nums)))"); ./push_swap $ARG | wc -l
```

### Error handling

The program displays `Error` on stderr in the following cases:
- Arguments that are not integers
- Arguments exceeding integer limits (overflow)
- Duplicate values
- Empty string argument

If no argument is given, the program exits silently. If the stack is already sorted, nothing is displayed.

### Cleaning

```bash
make clean    # Remove object files
make fclean   # Remove object files and binary
make re       # Recompile everything
```

## Resources

- [Push_swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — Detailed walkthrough of the cost-based algorithm
- [Visualizer for push_swap](https://github.com/o-reo/push_swap_visualizer) — Tool to visualize stack operations
- [Push_swap tester](https://github.com/LeoFu9487/push_swap_tester) — Automated tester for benchmarks

### AI usage

AI (Claude) was used as a learning companion during this project. It helped me understand the following concepts: the cost-based sorting algorithm, and edge case handling in parsing. The code was written step by step with explanations at each stage, followed by a review session to ensure full understanding of every component.