# Push_swap

## 📌 Project Overview

The idea is simple: you have two stacks called **Stack A** and **Stack B**.

Stack A is given a random list of unorganized numbers.  
Your goal is to sort Stack A in ascending order using a **limited set of operations** (called *actions*), while producing **as few operations as possible**.

> ⚠️ The challenge is not sorting itself, but doing it **efficiently**.

---

## 🧠 Theory

Before writing any algorithm for **push_swap**, we must understand **why efficiency matters**.

In this project, your program is **not judged by execution time**, but by the **number of operations** (`sa`, `pb`, `ra`, …) it prints.

### That means:

- A fast algorithm with **many moves** is bad ❌  
- A slower algorithm with **fewer moves** is good ✅  

This is where **algorithmic complexity** and **Big-O notation** come in.

---

## 📈 Complexity & Big-O Notation

**Complexity** describes how many **resources** an algorithm needs as the input size grows.

In **push_swap**, we mainly care about **time complexity**, meaning:

> How many operations does the algorithm perform when the number of elements increases?

**Big-O notation** is a mathematical way to describe this complexity in the **worst case**.

### Important points

- Big O **does not describe the best case**
- Big O **does not describe average cases**
- Big O describes **how bad the algorithm can get at worst**

### Examples

- `O(1)` → constant time (independent of input size)
- `O(n)` → linear growth
- `O(n²)` → quadratic growth (very expensive)

---

## 🔁 Allowed Actions

### Swap Actions

- **sa (swap a)**  
  Swap the first 2 elements at the top of stack A.

- **sb (swap b)**  
  Swap the first 2 elements at the top of stack B.

- **ss**  
  Perform `sa` and `sb` at the same time.

---

### Push Actions

- **pa (push a)**  
  Take the first element from stack B and put it on top of stack A.

- **pb (push b)**  
  Take the first element from stack A and put it on top of stack B.

---

### Rotate Actions

- **ra (rotate a)**  
  Shift all elements of stack A up by 1.

- **rb (rotate b)**  
  Shift all elements of stack B up by 1.

- **rr**  
  Perform `ra` and `rb` at the same time.

- **rra (reverse rotate a)**  
  Shift all elements of stack A down by 1.

- **rrb (reverse rotate b)**  
  Shift all elements of stack B down by 1.

- **rrr**  
  Perform `rra` and `rrb` at the same time.

---

## 🔍 Push_swap & Big-O

In **push_swap**:

- Each operation (`sa`, `pb`, `ra`, …) is **O(1)**  
  → they only move pointers, not the whole stack

- Scanning a stack once is **O(n)**

- Scanning a stack inside a loop over all elements is **O(n²)**

### Goal

> Avoid repeated full scans as much as possible.

---

## 🧩 Algorithm Strategy

The algorithm used depends on the **number of elements** in Stack A.

We handle **four main cases** differently:

- **3 elements**
- **5 elements**
- **100 elements**
- **500 elements**

Small inputs can be solved using **hardcoded logic**,  
while large inputs require a **scalable algorithm**.

---

## 🏷️ Indexing (Key Concept)

Before sorting large inputs, each value in Stack A is **indexed**:

- Smallest value → index `0`
- Largest value → index `n - 1`

### Why indexing?

- Faster comparisons
- No dependency on actual values
- Enables working with **ranges**

**Indexing complexity:**  
- One full traversal of the stack → **O(n)**

---

## 📦 Range / Chunk Algorithm (100 & 500)

For large inputs, the most efficient approach is the **range (chunk) algorithm**.

### Core Idea

Instead of pushing elements one by one, we:

1. Split values into **ranges (chunks)**
2. Push elements chunk by chunk from **A → B**
3. Push them back from **B → A** in sorted order

---

### Chunk Size

Chunk size is calculated dynamically:

```c
chunk_size = size * 0.05 + 10;
