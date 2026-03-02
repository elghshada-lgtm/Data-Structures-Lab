# Sorting Algorithms Lab (sorting 2)

---

## Task 1 
### Prove insertion sort is O(N^2) in the average-case

Insertion sort grows a sorted section on the left. On each pass i, the key may need to move left through some of the i elements already in the sorted part.  
In the average case, the key moves about half-way through that sorted part, so roughly i/2 comparisons and i/2 shifts happen on pass i.

Total average work:
(1/2)(1 + 2 + 3 + ... + (N-1))

= (1/2) * ((N-1)N / 2)

= N(N-1)/4

That grows like N^2, so insertion sort is **O(N^2)** on average.

Simple picture:
- left side is "sorted"
- key is inserted by shifting bigger values right until key fits

Example:
[2 4 6 8 | 5 7 9]

key = 5

shift 8, shift 6, stop after 4, insert 5

[2 4 5 6 8 | 7 9]

---

## Task 2
Given N = 5, array in descending order (worst case):

A = [5, 4, 3, 2, 1]

Count ONLY:
- comparison: A[j] > key
- shift: A[j+1] = A[j]

### (a) Start at i = 1. Verify total operations = 20
Worst case means each key moves all the way left.

Pass i=1: 1 comparison + 1 shift = 2  
Pass i=2: 2 comparisons + 2 shifts = 4  
Pass i=3: 3 comparisons + 3 shifts = 6  
Pass i=4: 4 comparisons + 4 shifts = 8

Total = 2 + 4 + 6 + 8 = **20** 

(output prints 20 total operations.)

### (b) Start at i = 2, then i = 3. Count operations again
Start i=2 means you only do passes i=2,3,4:
4 + 6 + 8 = **18**

Start i=3 means you only do passes i=3,4:
6 + 8 = **14**

(output prints 18 and 14.)

### (c) For (b), does the algorithm still sort the entire array?
No.

Insertion sort normally starts at i = 1 because it assumes the section left of i is already sorted.
If you start at i = 2, the "sorted part" would be indices 0..1, but in the worst-case array that is [5,4], which is NOT sorted.
So later insertions don’t guarantee the entire array becomes sorted.

---

## Task 3

### Given function
The original logic loops through every character and checks if any is 'X'.

### (a) Big-O time complexity
It may check all N characters, so time complexity is **O(N)**.

### (b) Improve best- and average-case
Stop early as soon as 'X' is found (early return).

In my code:
- `containsX_original` = checks all characters no matter what
- `containsX_improved` = returns immediately when it finds 'X'

Best case becomes O(1) if first character is X,
worst case stays O(N) if there is no X (or X is last).

## Here is my video link:
https://www.veed.io/view/af8cdeed-844e-4a1b-90dc-2550fab89959?source=editor&panel=share 
