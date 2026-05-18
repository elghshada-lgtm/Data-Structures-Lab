# Space Constraints Activity 
Shada Elghariani CISC 187
---

# Task 1

## Explanation
The `wordBuilder` algorithm makes a new collection that stores combinations of every pair of words in the array.

If the array contains `N` elements:

The outer loop runs `N` times. The inner loop would also runs `N` times. Approximately `N²` combinations are generated and stored. Because the algorithm stores all of these combinations in memory, the extra memory usage grows proportionally to `N²`. Therefore:

## Space Complexity
\[O(N^2)\]


# Task 2 

## Explanation
The function creates a new array and fills it with elements from the original array in reverse order.

If the input array has `N` elements:

A new array of size `N` is created and all elements are copied into this new array.

Even though the input array already exists, space complexity only counts **extra memory used**, and this algorithm requires an additional array of size `N`.

## Space Complexity
\[O(N)\]

--- 

# Task 3 

## Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

void reverseInPlace(vector<int>& array) {

    int left = 0;
    int right = array.size() - 1;

    while (left < right) {

        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }
}
```

## Explanation
This version reverses the array in place without creating a new array. The amount of extra memory stays constant regardless of the array size.

## Time Complexity
\[O(N)\]

## Space Complexity
\[O(1)\]

---

# Task 4 – Time and Space Complexity Comparison

| Version | Time Complexity | Space Complexity |
|----------|------------------|------------------|
| Version #1 | O(N) | O(N) |
| Version #2 | O(N) | O(1) |
| Version #3 | O(N) | O(N) |

---

# Version #1 Analysis

## Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> doubleArray1(vector<int> array) {

    vector<int> newArray;

    for (int i = 0; i < array.size(); i++) {
        newArray.push_back(array[i] * 2);
    }

    return newArray;
}
```

## Explanation
The loop processes every element once, so the time complexity is linear.

A new vector is created and stores all `N` elements, so the space complexity is also linear.

## Time Complexity
\[O(N)\]

## Space Complexity
\[O(N)\]

---

# Version #2 Analysis

## Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> doubleArray2(vector<int> array) {

    for (int i = 0; i < array.size(); i++) {
        array[i] *= 2;
    }

    return array;
}
```

## Explanation
The loop processes each element once.

No additional vector or data structure is created because the original array is modified directly.

## Time Complexity
\[O(N)\]

## Space Complexity
\[O(1)\]

---

# Version #3 Analysis

## Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

void doubleArray3(vector<int>& array, int index = 0) {

    if (index >= array.size()) {
        return;
    }

    array[index] *= 2;

    doubleArray3(array, index + 1);
}
```

## Explanation
This recursive function processes one element during every recursive call.

Even though no new vector is created, recursion uses additional memory through the call stack.

The call stack grows to size `N`, resulting in linear space complexity.

## Time Complexity
\[O(N)\]

## Space Complexity
\[O(N)\]

---
