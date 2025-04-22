# SquareMat

**Author**: adirofir123@gmail.com  
**Language**: C++17  
**Project**: Matrix Algebra Operator Overload Assignment

---

## 🧩 Overview

This project implements a modular, fully tested C++ class `SquareMat` representing real-number **square matrices** with a wide range of operations via **operator overloading**.

---

## ✨ Features

- Arithmetic operators: `+`, `-`, `*`, `/`, `%`
- Element-wise multiplication: `mat1 % mat2`
- Scalar math: `mat * scalar`, `scalar * mat`
- Unary minus: `-mat`
- Matrix power: `mat ^ int`
- Transpose: `~mat`
- Determinant: `!mat`
- Equality & comparisons: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Increment / Decrement: `++`, `--` (pre and post)
- Compound assignment: `+=`, `-=`, `*=`, `/=`, `%=` (matrix and scalar)
- Output stream: `<<` to `std::ostream`
- Bounds-checked access: `mat[i][j]`
- Full test coverage with [doctest](https://github.com/doctest/doctest)
- Memory safety tested via `valgrind`

---

## 📁 Folder Structure

```
Project2/
├── SquareMat.h        # Header file
├── SquareMat.cpp      # Implementation
├── main.cpp           # Demo executable
├── tests/
│   └── test.cpp       # Unit tests (doctest.h included here)
├── doctest.h          # Testing header
├── Makefile           # Build and test automation
└── README.md          # You're here
```

---

## 🛠 Makefile Commands

```bash
make Main       # Build and run main.cpp
make test       # Compile and run tests with doctest
make valgrind   # Run valgrind memory check on main
make clean      # Remove compiled files (Main, test, *.o)
```

---

## ✅ Example Output

```bash
Final Matrix:
0 2 
1 0 
Determinant: -2
```

---

## 💡 Notes

- All matrix operations require matching sizes.
- Throws `std::invalid_argument` on invalid input (e.g., division by 0, size mismatch).
- Determinant calculation uses recursive expansion (efficient enough for small N).

---

## 🚀 Done!

Thanks for reading! Good luck with grading 😄
