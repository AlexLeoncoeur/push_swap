# Push Swap

## Introduction

Push Swap is a sorting algorithm project designed to help you understand and implement various sorting techniques using two stacks, `a` and `b`. The goal is to sort a list of integers in ascending order with the minimum number of operations. The allowed operations are predefined and must be used effectively to achieve the optimal result.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Operations](#operations)
- [Sorting Algorithms](#sorting-algorithms)
  - [Sorting by Costs](#sorting-by-costs)
  - [Sorting 2, 3, or More Numbers](#sorting-2-3-or-more-numbers)
- [Examples](#examples)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Features

- Efficient sorting of integers using stack-based operations.
- Implementation of various sorting algorithms.
- Handling of errors and edge cases.
- Optimization to minimize the number of operations.

## Requirements

- A C compiler (gcc or clang).
- Make.
- Basic understanding of stacks and sorting algorithms.

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/your_username/push_swap.git
    cd push_swap
    ```

2. Compile the project:

    ```bash
    make
    ```

## Usage

Run the `push_swap` program with a list of integers to sort:

```bash
./push_swap [list of integers]
```

For example:

```bash
./push_swap 4 67 3 87 23
```

## Operations

The allowed operations are:

- `sa`: Swap the first two elements at the top of stack `a`.
- `sb`: Swap the first two elements at the top of stack `b`.
- `ss`: `sa` and `sb` at the same time.
- `pa`: Push the first element at the top of stack `b` to stack `a`.
- `pb`: Push the first element at the top of stack `a` to stack `b`.
- `ra`: Rotate stack `a` (shift all elements up by 1).
- `rb`: Rotate stack `b` (shift all elements up by 1).
- `rr`: `ra` and `rb` at the same time.
- `rra`: Reverse rotate stack `a` (shift all elements down by 1).
- `rrb`: Reverse rotate stack `b` (shift all elements down by 1).
- `rrr`: `rra` and `rrb` at the same time.

## Sorting Algorithms

### Sorting by Costs

The sorting by costs algorithm aims to minimize the total number of operations required to sort the stack. The main idea is to calculate the "cost" of moving each element into its correct position and then execute the sequence of operations that has the lowest cost. 

The cost for each element can be calculated based on the number of moves needed to bring it to the top of its current stack and then to its correct position in the sorted stack. The possible moves include rotations and reverse rotations. By evaluating the cost for each possible move, we can determine the most efficient sequence of operations to sort the stack.

### Sorting 2, 3, or More Numbers

#### Sorting 2 Numbers

Sorting 2 numbers is straightforward and can be done with a single `sa` operation if the numbers are in the wrong order.

Example:
```bash
./push_swap 2 1
```
Expected output:
```bash
sa
```

#### Sorting 3 Numbers

Sorting 3 numbers involves more combinations, but can still be done efficiently with a few operations. The possible permutations and corresponding operations are:

- `3 2 1` -> `sa` -> `2 3 1` -> `rra` -> `1 2 3`
- `3 1 2` -> `ra` -> `1 2 3`
- `2 3 1` -> `rra` -> `1 2 3`
- `2 1 3` -> `sa` -> `1 2 3`
- `1 3 2` -> `sa` -> `3 1 2` -> `ra` -> `1 2 3`

Example:
```bash
./push_swap 3 2 1
```
Expected output:
```bash
sa
rra
```

#### Sorting More Numbers

For larger sets of numbers, the algorithm involves splitting the list into manageable chunks, pushing parts of the list to stack `b`, and then sorting and merging them back into stack `a` using the predefined operations. This process includes:

1. Finding the median and pushing elements below the median to stack `b`.
2. Recursively sorting the remaining elements in stack `a`.
3. Pushing elements back from stack `b` to stack `a` in the correct order.

This divide and conquer approach helps manage the complexity and reduces the number of operations needed.

## Examples

To see how the program works, you can use the following example:

```bash
./push_swap 3 2 1
```

Expected output:

```bash
sa
rra
```

## Testing

To check the validity and efficiency of your solution, you can use the provided checker program:

1. Compile the checker:

    ```bash
    make bonus
    ```

2. Run the checker with your operations:

    ```bash
    ./push_swap [list of integers] | ./checker [list of integers]
    ```

For example:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Expected output:

```bash
OK
```

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a pull request.

## License

Distributed under the MIT License. See `LICENSE` for more information.
