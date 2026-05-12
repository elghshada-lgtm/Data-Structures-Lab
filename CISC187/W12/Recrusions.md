# Recursions Activity
Shada Elghariani
CISC 187 

---

## Task 1: Identify the base case in the function:

### Code Given:
```cpp
def print_every_other(low, high) 
    return if low > high
    puts low
    print_every_other(low + 2, high)
end
``` 
### Answer:

The base case is:
low > high

### Explanation:

This condition stops the recursion when the low value becomes greater than the high value. Without it, the function would run forever.

## Task 2: Predict what will happen when we run factorial(10) using the function
Code Given:
```cpp
def factorial(n)
return 1 if n == 1
return n * factorial(n - 2)
end
```
### Answer:

When calling factorial(10), the function will compute:
```cpp
10 × 8 × 6 × 4 × 2 × factorial(0)
```
However there is no base case for n = 0 or negative numbers.

### Final Result:

The function will fail to terminate properly and will eventually cause a stack overflow or runtime error.

Fix:
return 1 if n <= 1

## Task 3: Fix the code by adding the correct base case
### Code Given:
```cpp
def sum(low, high)
return high + sum(low, high - 1)
end
```
### Problem:

The function has no stopping condition, so it runs indefinitely.

### Corrected Code:
```cpp
def sum(low, high)
return low if low == high
return high + sum(low, high - 1)
end
```
### Explanation:
The recursion stops when high == low, and then starts returning values back up.


## Task 4: Write a recursive function that prints all the numbers (and just numbers)


Solution:
```cpp 
#include <iostream>
#include <vector>

using namespace std;

void printNumbers(vector<int>& arr, int index) {

    // base case
    if (index == arr.size()) {
        return;
    }

    // print current number
    cout << arr[index] << endl;

    // recursive call
    printNumbers(arr, index + 1);
}

int main() {

    vector<int> arr = {
        1,2,3,4,5,6,7,8,9,10,
        11,12,13,14,15,16,17,18,19,20,
        21,22,23,24,25,26,27,28,29,30,
        31,32,33
    };

    printNumbers(arr, 0);

    return 0;
}
```

### Explanation:
Base case:
When the index becomes equal to the size of the array, the recursion stops.

Recursive case:
The function prints the current number and then recursively moves to the next index.
