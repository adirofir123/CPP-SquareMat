# SquareMat

**Author**: adirofir123@gmail.com  
**Language**: C++17  
**Project**: Matrix Algebra Operator Overload Assignment

---

## Overview

This project implements a modular, fully tested C++ class `SquareMat` representing real-number **square matrices** with a wide range of operations via **operator overloading**.  
The matrix is internally managed with **dynamic memory allocation** (`new[]`, `delete[]`), **without** using STL containers (`vector`).

---

## Features

- Arithmetic operators: `+`, `-`, `*`, `/`, `%`
- Element-wise multiplication: `mat1 % mat2`
- Scalar operations: `mat * scalar`, `scalar * mat`
- Unary minus: `-mat`
- Matrix exponentiation: `mat ^ int`
- Transpose operator: `~mat`
- Determinant operator: `!mat`
- Equality & comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Pre- and post-increment/decrement: `++`, `--`
- Compound assignments: `+=`, `-=`, `*=`, `/=`, `%=` (with matrix or scalar)
- Output stream operator: `<<` (printing matrix)
- Bounds-checked access: `mat[i][j]`
- Full test coverage with [doctest](https://github.com/doctest/doctest)
- Memory safety validated with `valgrind`

---

## Folder Structure

```
Project2/
├── SquareMat.h        # Class declaration (header)
├── SquareMat.cpp      # Class implementation (dynamic memory)
├── main.cpp           # Demo executable
├── tests/
│   ├── test.cpp       # Unit tests using doctest
│   └── doctest.h      # Testing library
├── Makefile           # Build and test automation
└── README.md          # This file
```

---

## Makefile Commands

```bash
make Main       # Build and run main.cpp
make test       # Compile and run tests with doctest
make valgrind   # Run valgrind memory check on Main
make clean      # Remove compiled files (Main, test, *.o)
```

---

## Example Output

```
Matrix 1:
1 2
3 4

Matrix 2:
5 6
7 8

Sum:
6 8
10 12

Product:
19 22
43 50
```

---

## Notes

- All matrix operations require matrices of the same size.
- Throws `std::invalid_argument` for invalid operations (e.g., division by zero, size mismatch).
- Determinant calculation uses recursive Laplace expansion (suitable for small matrices, up to 4x4 or 5x5).
- Manual memory management is carefully handled — project validated to have **zero memory leaks**.

---

