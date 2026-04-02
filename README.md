# Gauss-Jordan Elimination Solver

**A simple C program to solve system of linear equations using Gauss-Jordan Elimination method.**

Written in **2024** by **Chandan Das**.

---

## Purpose

This program takes an augmented matrix as input and:
- Performs Gauss-Jordan elimination to reduce it to row echelon form
- Prints the reduced matrix
- Determines the rank of coefficient and augmented matrices
- Checks consistency and provides the solution (unique / infinite / no solution)

It supports up to 10×10 matrices and uses partial pivoting for better numerical stability.

## Features

- Full Gauss-Jordan elimination (not just forward elimination)
- Row swapping for zero pivots
- Floating-point precision handling with EPS
- Consistency check (unique solution, infinite solutions, or inconsistent)
- Clean menu-driven interface
- Cross-platform (Windows + Linux/macOS)

## How to Compile and Run

### Prerequisites
- GCC compiler (or any C compiler)

### Compilation
```bash
gcc -o gauss_jordan gauss_jordan.c -lm
```
### Run
```bash
./gauss_jordan
```

### Usage Example
**System of equations:**
```
5x + 4y = 28
7x + 2y = 39
```
**Input:**
```
Enter row and col of augmented matrix (limit <=10): 2 3
Enter matrix elements:
5 4 28
7 2 39
```
**Output:**
```
Row reduced form:
    1.0000     0.0000     5.5556
    0.0000     1.0000     0.0556

Rank of augmented matrix: 2
Rank of coefficient matrix: 2
System is consistent.
Unique solution:
(x = 5.5556, y = 0.0556)
```
### Limitations

* Maximum matrix size: 10×10
* Handles real numbers only (no complex numbers)
* Parametric solution for infinite cases is not fully implemented yet

### Future Improvements (Planned)

* Better partial pivoting (maximum element)
* Parametric form printing for infinite solutions
* Determinant calculation for square matrice

## Development Journey

This project was first written in 2024 as a basic implementation using manual row operations and `goto` statements (original "hustle" version). No modularity, everything is in `main()` function.
I later rewrote it with proper Gauss-Jordan elimination, better pivoting, floating-point safety using EPS. But the original provided **Parametric form printing for infinite solutions** . Thus, I want to include the improved parametric solution for infinite cases.

The current version is cleaner, more reliable, and follows better C programming practices.
