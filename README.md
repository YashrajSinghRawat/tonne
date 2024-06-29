# C Utilities Library

## Overview

This library provides a collection of macros and functions designed to enhance the C programming experience by adding convenience and functionality similar to higher-level languages. It includes type definitions, iteration macros, logical operators, memory allocation shortcuts, and string manipulation functions.

## Features

### Type Definitions

- **Floating Point Types**: `float32_t`, `float64_t`, `float128_t` for 32, 64, and 128-bit floating-point numbers.
- **Integer Types**: `uchar`, `ushort`, `uint`, `ulong`, `ularge`, `large` for various unsigned and signed integers.
- **Type Macros**: `int(bit)`, `uint(bit)`, `float(bit)` for creating integer and floating-point types with specific bit sizes.

### Iteration Macros

- **For Loops**: `for_n`, `for_fn`, `rfor_n`, `rfor_fn`, `for_m` for various forms of for-loops.
- **Logical Operators**: `and`, `or`, `not` as alternatives to `&&`, `||`, `!`.
- **Parity Checkers**: `is_odd`, `is_even` for checking the parity of numbers.

### Memory Allocation

- **Allocation Macros**: `nalloc`, `ralloc` for allocating and reallocating memory.
- **Pointer Array Builders**: `builder`, `make_pptr` for creating pointer arrays.

### Functional Programming

- **Functional Macros**: `next`, `sum`, `product`, `any`, `all` for applying functions to elements.

### Array Utilities

- **Array Length**: `arrlen` for getting the length of an array.
- **Array Builder**: `array` for creating arrays in a block scope.

### Pointer Utilities

- **Pointer Creation**: `ptr`, `pinit` for creating and initializing pointers.
- **Pointer Array Length**: `pptrlen` for computing the length of a pointer array.

### Random Number Generation

- **Random Integers**: `randint` for generating random integers within a range.
- **Random Floats**: `randf` for generating random floating-point numbers within a range.

### String Manipulation

- **String Concatenation**: `concat` for concatenating two strings.
- **String Joining**: `join` for joining multiple strings with a specified separator.

## Usage

Include the header file in your project and use the macros and functions as needed to simplify your C code and add functionality that is typically found in higher-level languages.

## License

This library is open-source and free to use. Please provide attribution if you use it in your projects.
