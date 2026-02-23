# Sorting Algorithms Project

Name: Shada Elghariani  
Course: Data Structures in C++  
Lab: Sorting Algorithms

---

## Introduction

A sorting algorithm rearranges a collection of items (usually numbers) 
into ascending or descending order. Sorting is crucial because many faster algorithms 
(like binary search) require sorted input data.

In this project, we implement three sorting methods:

• Bubble Sort  
• Selection Sort  
• Insertion Sort

We count and display **steps** (comparisons + swaps) to show how efficient each algorithm is.


---

## Algorithms Used

###  1. Bubble Sort
Bubble Sort repeatedly swaps adjacent items that are out of order. 
It keeps going until no more swaps happen.
Time Complexity:
- Best case: O(n)
- Worst & average case: O(n²)

---

###  2. Selection Sort
Selection Sort finds the smallest unsorted item and places it at the start of the sorted section. 

Time Complexity:
- O(n²) in all cases

---

###  3. Insertion Sort
Insertion Sort inserts each new item into its correct place in a growing sorted list. 

Time Complexity:
- Best: O(n)
- Worst & average: O(n²)

---

## Output Example
Original array: 8 3 5 2 9 1
Bubble sorted: 1 2 3 5 8 9
Bubble Sort steps: 21

Original array: 8 3 5 2 9 1
Selection sorted: 1 2 3 5 8 9
Selection Sort steps: 15

Original array: 8 3 5 2 9 1
Insertion sorted: 1 2 3 5 8 9
Insertion Sort steps: 16

---

## Step Counting Rules

We count 1 step for:
• Every **comparison** between elements  
• Every **swap** of two elements

Step counting helps analyze algorithm efficiency as data size grows.

---

## Conclusion
Sorting is a basic yet essential computation in data structures.
Even simple algorithms like Bubble, Selection, and Insertion sorting 
reveal how performance can be different even with similar time complexities.
