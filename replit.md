# Ejercicios sobre el uso de Listas y Pilas

A C-based lab assignment for practicing Abstract Data Types (Linked Lists and Stacks).

## Project Overview

Students implement five exercises in `exercises.c` using a provided List ADT and Stack ADT. A test suite automatically grades the work.

## Structure

- `exercises.c` — Student implementation file (the only file to edit)
- `arraylist.h` / `arraylist.c` — List ADT implementation
- `stack.h` — Stack ADT (wrapper around the List)
- `test.c` — Test suite (grading, do not modify)
- `test.sh` — Build + run script

## How to Run

Use the **Run Tests** workflow (or run `bash test.sh` in the shell). The script:
1. Compiles `test.c` with `gcc -g -Wall -Werror`
2. Runs the test suite and shows pass/fail for each exercise
3. Reports a score out of 70
4. Optionally pushes progress to GitHub (requires a personal access token)

## System Dependencies

- `gcc` (GCC 14, available via Nix `bash` module)
- `gdb` (installed via Nix system dependency)

## Workflow

- **Run Tests** — runs `bash test.sh` (console output)

## Exercises

1. `crea_lista()` — Create a list with integers 1–10 (10 pts)
2. `sumaLista()` — Sum all elements of a list (10 pts)
3. `eliminaElementos()` — Remove all elements equal to a given value (20 pts)
4. `copia_pila()` — Copy a stack while preserving order (10 pts)
5. `parentesisBalanceados()` — Check if parentheses in a string are balanced (20 pts)
