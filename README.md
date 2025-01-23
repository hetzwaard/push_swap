# push_swap

## Overview
The **push_swap** project is about sorting a stack of integers using two stacks: `a` and `b`, and a set of specific operations. The goal is to sort the stack `a` in ascending order using the fewest possible moves.

In this project, I implemented the **Radix Sort** algorithm as the primary sorting method, along with some additional functions to handle smaller input sizes.

---

## Features
- **Radix Sort Implementation:** Efficiently sorts stacks of any size.
- **Custom Stack Operations:**
  - `sa`, `sb`, `ss`: Swap the first two elements of a stack.
  - `pa`, `pb`: Push the top element from one stack to another.
  - `ra`, `rb`, `rr`: Rotate a stack upwards.
  - `rra`, `rrb`, `rrr`: Rotate a stack downwards.
- **Extra Sorting Functions:**
  - `sort_three`: Optimized sorting for three elements.
  - `sort_four_to_five`: Handles cases with four or five elements efficiently.
- Handles edge cases such as duplicate values, invalid input, and small input sizes.
- Outputs the sequence of operations to sort the stack.

---

## Algorithm Explanation
### **Radix Sort**
Radix Sort is a non-comparative sorting algorithm that processes each digit of the numbers (from least significant to most significant) to sort the elements. In this stack-based implementation:

1. **Indexing:** All values in the stack are indexed based on their sorted order using a helper function.
2. **Bitwise Processing:**
   - For each bit (starting from the least significant bit):
     - Push numbers with a `0` in the current bit to stack `b`.
     - Keep numbers with a `1` in stack `a`.
   - Move all numbers back to stack `a` from stack `b`.
3. **Repeat:** Repeat this process for all bits of the largest number in the stack.
4. **Sorted Stack:** After processing all bits, stack `a` will be sorted in ascending order.

### **Small Input Handling**
- **2 Elements:** Directly swaps the elements if needed.
- **3 Elements:** Uses `sort_three` to find the highest element and rotates/swaps accordingly.
- **4-5 Elements:** Finds the smallest element(s), moves them to stack `b`, sorts the remaining elements using `sort_three`, and reintegrates the smallest element(s).

---

## How to Use
### Prerequisites
- A C compiler (e.g., `gcc`).
- GNU Make.

### Compilation
To compile the project, run the following command:
```bash
make
```

### Usage
1. Run the program with a list of integers to sort:
```bash
./push_swap [numbers]
```
Example:
```bash
./push_swap 5 2 8 3 1
```

2. The program will output the sequence of operations to sort the numbers.

3. To check the number of operations used:
```bash
./push_swap 5 2 8 3 1 | wc -l
```

---

Explanation:
- `pb` pushes elements from `a` to `b`.
- `ra` rotates stack `a` upwards.
- `pa` pushes elements from `b` back to `a`.

---

## Project Structure
- `push_swap.c`: Main file containing the program logic.
- `radix_sort.c`: Implementation of the Radix Sort algorithm.
- `stack_operations.c`: Functions to handle stack operations.
- `sort_helpers.c`: Functions for sorting small numbers of elements.
- `utils.c`: Helper functions (e.g., error handling, parsing, indexing).
- `Makefile`: Build configuration.

---

## Testing
You can test the program with random integers using this command:
```bash
ARG="$(seq -100 100 | shuf | head -n 10)"; ./push_swap $ARG
```
This will generate a random set of 10 numbers between -100 and 100, then sort them.

---

## Notes
- The program is designed to handle valid input only. Ensure all inputs are integers without duplicates.
- The `stack_init` function performs input validation and error handling.
- The Radix Sort algorithm ensures efficient sorting for larger stacks, while smaller inputs are handled using optimized auxiliary functions.

---

## Acknowledgments
Special thanks to the 42 Network, Codam College (42 Amsterdam), and its community for inspiring this project.

---

## Contact
For questions or suggestions, feel free to reach out:
- Email: me@mahmutkilic.nl
