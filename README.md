# Push Swap  
![C Programming](https://img.shields.io/badge/Language-C-blue)  
![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen)  
![License](https://img.shields.io/badge/License-MIT-green)  
![Platform](https://img.shields.io/badge/Platform-Linux%20|%20macOS-lightgrey)  

A sorting algorithm project from [42 School](https://www.42.fr/). **Push Swap** is a program that sorts a stack of integers using a predefined set of operations, striving for minimal moves. This repository contains the implementation and resources for understanding the project.

---

## 📋 Table of Contents  
- [📖 Overview](#-overview)  
- [✨ Features](#-features)  
- [🛠 Requirements](#-requirements)  
- [📥 Installation](#-installation)  
- [🚀 Usage](#-usage)  
- [📚 Operations](#-operations)  
- [📊 Evaluation](#-evaluation)  
- [📜 License](#-license)  

---

## 📖 Overview  
The **Push Swap** program takes a sequence of integers as input and outputs a series of stack operations to sort them in ascending order. This is achieved under specific constraints:  

- Only two stacks are allowed: `a` (input) and `b` (empty at the start).  
- Only a limited set of operations can be used (e.g., `sa`, `pb`, `ra`, etc.).  
- The goal is to achieve optimal sorting in as few operations as possible.  

This project is designed to test algorithmic thinking and proficiency in low-level programming concepts.

---

## ✨ Features  
- Implements efficient sorting algorithms like **Quicksort** or **Merge Sort** tailored for stack-based sorting.  
- Provides verbose output for debugging and understanding the sorting process.  
- Complies with the constraints defined by the project guidelines at 42 School.  

---

## 🛠 Requirements  
- **Compiler:** GCC or Clang  
- **Dependencies:** None (pure C implementation)  
- **OS Compatibility:** Linux, macOS  

---

## 📥 Installation  
1. Clone this repository:  
   ```bash
   git clone https://github.com/username/push_swap.git
   cd push_swap

2. Compile the program:  
   ```bash
   make

## 🚀 Usage
Run the program with a list of integers as arguments:

```bash
./push_swap 4 67 3 87 23

The program outputs a series of operations to sort the integers:

```text

pb
ra
pb
sa
pa
pa
## 🔍 Example with Checker
To verify correctness, use the provided checker program:

Pipe operations into checker:
```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
checker will output:
OK if sorted correctly
KO if the result is unsorted or invalid

## 📚 Operations
The following operations are used to manipulate stacks:

Operation	Description
sa	Swap the first two elements of stack a.
sb	Swap the first two elements of stack b.
ss	Perform sa and sb simultaneously.
pa	Push the top element of stack b to stack a.
pb	Push the top element of stack a to stack b.
ra	Rotate stack a upwards.
rb	Rotate stack b upwards.
rr	Perform ra and rb simultaneously.
rra	Reverse rotate stack a.
rrb	Reverse rotate stack b.
rrr	Perform rra and rrb simultaneously.

## 📊 Evaluation
The program is graded on:

Correctness: Properly sorting inputs.
Efficiency: Using minimal operations for large datasets.
Edge Cases: Handling duplicates, negative numbers, and invalid inputs gracefully.

## 📜 License
This project is licensed under the MIT License. See the LICENSE file for details.
