# Push_swap

## 📌 Project Overview

The idea is simple: you have two stacks called Stack A and Stack B.

Stack A is given a random list of unorganized numbers.
Your goal is to sort Stack A in ascending order using a limited set of operations (called actions),
while producing as few operations as possible.

The challenge is not sorting itself, but doing it efficiently.

--------------------------------------------------------------------

## 🧠 Theory

Before writing any algorithm for push_swap, we must understand why efficiency matters.

In this project, your program is not judged by execution time,
but by the number of operations (sa, pb, ra, …) it prints.

That means:

- A fast algorithm with many moves is bad
- A slower algorithm with fewer moves is good

This is where algorithmic complexity and Big-O notation come in.

--------------------------------------------------------------------

## 📈 Complexity & Big-O Notation

Complexity describes how many resources an algorithm needs as the input size grows.

In push_swap, we mainly care about time complexity:

How many operations does the algorithm perform when the number of elements increases?

Big-O notation describes this complexity in the worst case.

Important points:

- Big O does not describe the best case
- Big O does not describe average cases
- Big O describes how bad the algorithm can get at worst

Examples:

- O(1)  -> constant time
- O(n)  -> linear growth
- O(n²) -> quadratic growth

--------------------------------------------------------------------

## 🔁 Allowed Actions

Swap Actions:
- sa  : swap first two elements of stack A
- sb  : swap first two elements of stack B
- ss  : sa and sb at the same time

Push Actions:
- pa  : push top of B to A
- pb  : push top of A to B

Rotate Actions:
- ra  : rotate stack A up
- rb  : rotate stack B up
- rr  : ra and rb together
- rra : reverse rotate stack A
- rrb : reverse rotate stack B
- rrr : rra and rrb together

--------------------------------------------------------------------

## 🔍 Push_swap & Big-O

- Each operation (sa, pb, ra, …) is O(1)
- Scanning a stack once is O(n)
- Scanning inside a loop is O(n²)

Goal:
Avoid repeated full scans as much as possible.

--------------------------------------------------------------------

## 🧩 Algorithm Strategy

The algorithm depends on the number of elements:

- 3 elements
- 5 elements
- 100 elements
- 500 elements

Small inputs use hardcoded logic.
Large inputs use a scalable algorithm.

--------------------------------------------------------------------

## 🏷️ Indexing (Key Concept)

Each value is replaced by an index:

- Smallest value -> index 0
- Largest value  -> index n - 1

Why indexing?

- Faster comparisons
- No dependency on real values
- Enables range-based logic

Indexing complexity:
O(n)

--------------------------------------------------------------------

## 📦 Range / Chunk Algorithm (100 & 500)

Core idea:

1. Split values into chunks
2. Push chunks from A to B
3. Push elements back from B to A in sorted order

--------------------------------------------------------------------

## 📐 Chunk Size

Chunk size is calculated dynamically:

chunk_size = size * 0.05 + 10

Explanation:

- size * 0.05 takes 5% of the stack
- +10 guarantees a minimum chunk size

This reduces rotations and useless moves.
It improves performance in practice but does NOT change Big-O.

--------------------------------------------------------------------

## 🚚 Step 1: Push Chunks from A → B

- Loop through stack A
- If index is inside the current range -> pb
- Rotate intelligently
- Expand the range progressively

Each element:
- Handled once
- Uses O(1) operations

Complexity:
O(n)

--------------------------------------------------------------------

## 🔄 Step 2: Push Max from B → A

- Find the maximum index in stack B
- Rotate B until max is on top
- Push it back to A
- Repeat until B is empty

Worst case:
- Finding max is O(n)
- Done for n elements

Complexity:
O(n²)

--------------------------------------------------------------------

## ⚠️ Worst Case of the Range Algorithm

The worst case happens during the B → A phase when:

- The maximum element is far from the top
- Stack B is scanned and rotated many times

Even with chunking, the algorithm still has:

Worst-case time complexity: O(n²)

--------------------------------------------------------------------

## ✅ Conclusion

Even though the range algorithm has a worst-case complexity of O(n²),
indexing and chunking drastically reduce the number of operations in practice,
making it efficient for large inputs.
