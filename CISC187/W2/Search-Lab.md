# Searching  Lab
 
* Name: Shada Elghariani
* Course: Data Structures in C++

## Tasks

### 1. Linear Search
- Go through the list one by one until you find the number.
- Step counting example:
    - List: `[2, 4, 6, 8, 10, 12, 13]`
    - Search for `8` → takes 4 steps.
- Big-O: O(N)

### 2. Binary Search
- Works only on sorted lists.
- Check the middle number, then search left or right half.
- Step counting example:
    - Same list as above → takes 2 steps.
- Big-O: O(log N)

### 3. Randomized Search
- Pick random indices without repeating until the number is found.
- Can be better than linear search in rare cases but usually slower than binary search on sorted lists.
- Best case: O(1)
- Average case: O(N)
- Worst case: O(N)

---

## 4. Implementation Details
- using an array/vector of **100,000 numbers**.
- The program counts the number of comparisons for each search method.
- Only standard C++ libraries are used:
    - `<vector>`
    - `<random>`
    - `<iostream>`

---

## 5. Comparison
| Search Method | Requirements | Complexity | Practical Use |
|---------------|--------------|-----------|---------------|
| Linear Search | None | O(N) | Small or unsorted lists |
| Binary Search | Sorted list | O(log N) | Large sorted lists, very fast |
| Randomized Search | None, no repeats | O(N) average | Unsorted lists, for random access experiments |

---
## Conclusions

- Binary search is much faster on large sorted lists.
- Linear and randomized search are simple but slower on large lists.
- Use binary search when the array is sorted and you want fast lookup.
---

## Video Link:
- https://www.veed.io/view/2c7b26e6-00d1-4fdb-9b52-e2123e268867?source=Homepage&panel=share 
