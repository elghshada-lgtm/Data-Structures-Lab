# Adaptive Sorting Lab – Part C

---

## How the Program Analyzes the Array

To understand how ordered the array is, the program counts something called **descents**.

### What is a descent?

A descent happens when a number is bigger than the number right after it:

a[i] > a[i + 1]

Since the array has 50 elements, there are **49 possible places** where a descent can occur.

- If there are only a few descents, the array is almost sorted
- If there are many descents, the array is close to being in reverse order

This lets the program decide how “good” or “bad” the input already is without sorting it first.

---

## Thresholds Used

The number of descents is used to classify the array:

- **Best Case:** 0–2 descents  
  The array is nearly sorted

- **Average Case:** 3–39 descents  
  The array is mostly random

- **Worst Case:** 40–49 descents  
  The array is nearly in descending order

These thresholds are clearly defined and used consistently in the program.

---

## Part A: Adaptive Sorting

### What Happens in Part A

1. The program creates an array of 50 random integers
2. It counts how many descents the array has
3. The array is classified as best, average, or worst case
4. A sorting algorithm is chosen automatically
5. The array is then sorted

### Why Each Algorithm Is Chosen

- **Insertion Sort** is used when the array is already almost sorted
- **Selection Sort** is used for average and worst-case inputs

This makes sense because:
- Insertion Sort is very fast when the data is nearly sorted
- Selection Sort always takes the same amount of time no matter how the data looks

Using insertion sort for nearly sorted data helps the program run more efficiently.

---

## Part B: Classification Without Sorting

### What Happens in Part B

1. The user enters 50 integers
2. The program does not sort the array
3. It counts the number of descents
4. The array is classified as either average or worst case

### Classification Rules

- 40 or more descents → **Worst Case**
- Fewer than 40 descents → **Average Case**

A best case classification is not required for Part B, so it is not included.

---

## Time Complexity

**Insertion Sort**
- Best case: O(N)
- Average case: O(N²)
- Worst case: O(N²)

**Selection Sort**
- Best case: O(N²)
- Average case: O(N²)
- Worst case: O(N²)

---
