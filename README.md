# C Utilities Library

## Overview

This library provides a collection of macros and functions designed to enhance the C programming experience by adding convenience and functionality similar to higher-level languages. It includes type definitions, iteration macros, logical operators, memory allocation shortcuts, and string manipulation functions.

## Features

### Type Definitions

- **Floating Point Types**: `float32_t`, `float64_t`, `float128_t` for 32, 64, and 128-bit floating-point numbers.
- **Integer Types**: `uchar`, `ushort`, `uint`, `ulong`, `ularge`, `large` for various unsigned and signed integers.
```c
uchar c = 255; // 8-bit unsigned
large d = 11234564879; // long long integer
```
- **Type Macros**: `int(bit)`, `uint(bit)`, `float(bit)` for creating integer and floating-point types with specific bit sizes.
```c
int(8) a = 100; // 8-bit integer
float(64) b = 2.5e-10; // 64-bit float
```

### Iteration Macros

- **For Loops**: `for_n`, `for_fn`, `rfor_n`, `rfor_fn`, `for_m` for various forms of for-loops.
```c
for_n(_, 10) printf("%d ", _); // 0 1 2 3 4 5 6 7 8 9
for_fn(_, 10, 20) printf("%d", _); // 10 11 12 13 14 15 16 17 18 19
```
- **Logical Operators**: `and`, `or`, `not` as alternatives to `&&`, `||`, `!`.
```c
if (12 / 2 == 6 and 42 < 50 or 95 % 5 < 4)
  printf("I am a Mathematician\n");
else printf("Mujhe maths nhi aati\n");
```
- **Parity Checkers**: `is_odd`, `is_even` for checking the parity of numbers.
```c
if (is_odd(24) or is_even(9))
  printf("I am a mentle peice.\n)
```

### Memory Allocation

- **Allocation Macros**: `nalloc`, `ralloc` for allocating and reallocating memory.
```c
int *a = nalloc(int, 10);
for_n(i, 10) a[i] = i + 1;
for_n(i, 10) printf("%d ", a[i]); // 1 2 3 4 5 6 7 8 9 10
free(a);
```
- **Pointer Array Builders**: `builder`, `make_pptr` for creating pointer arrays.
```c
int *a = builder(int, i, for_n(i, 10));
for_n(i, 10) printf("%d ", a[i]); // 0 1 2 3 4 5 6 7 8 9
free(a);
```

### Functional Programming

- **Functional Macros**: `next`, `sum`, `product`, `any`, `all` for applying functions to elements.
```c
int a = next(int, i, for_n(i, 10) if (i > 5), -1)
printf("%d", a); // 6
a = sum(int, i, for_n(i, 10));
printf("%d", a); // 45
if (all(i > 0, for_fn(i, 1, 11)))
  printf("Numbers from 1 to 10 are greater than 0\n");
```

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
