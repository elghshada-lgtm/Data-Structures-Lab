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
Here is the code for this lab:
``` cpp

#include <iostream>
#include <vector>
#include <ctime>
#include <limits>

using namespace std;

const int N = 50;

// Thresholds
const int BEST_DESCENTS  = 2;   // 0..2 drops -> almost sorted
const int WORST_DESCENTS = 40;  // 40..49 drops -> very descending

// Selection Sort
void selectionSort(vector<int>& a) {
    for (int i = 0; i < (int)a.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < (int)a.size(); j++) {
            if (a[j] < a[minIndex]) minIndex = j;
        }
        swap(a[i], a[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Count descents: a[i] > a[i+1]
int countDescents(const vector<int>& a) {
    int d = 0;
    for (int i = 0; i < (int)a.size() - 1; i++) {
        if (a[i] > a[i + 1]) d++;
    }
    return d;
}

string scenarioFromDescents(int d) {
    if (d <= BEST_DESCENTS) return "BEST";
    if (d >= WORST_DESCENTS) return "WORST";
    return "AVERAGE";
}

// PART A
void partA() {
    vector<int> a(N);
    srand((unsigned)time(nullptr));

    // Create an array of 50 integers (random example)
    for (int i = 0; i < N; i++) a[i] = rand() % 1000;

    int d = countDescents(a);
    string scenario = scenarioFromDescents(d);

    cout << "Part A Analysis:\n";
    cout << "Descents = " << d << " out of 49\n";
    cout << "Scenario = " << scenario << "\n";

    if (scenario == "BEST") {
        cout << "Chosen algorithm: Insertion Sort\n";
        insertionSort(a);
    } else {
        cout << "Chosen algorithm: Selection Sort\n";
        selectionSort(a);
    }

    cout << "Part A Done: Array sorted.\n\n";
}

// PART B
void partB() {
    vector<int> a(N);

    cout << "Enter 50 integers (spaces and new lines ONLY, no commas):\n";
    for (int i = 0; i < N; i++) {
        while (!(cin >> a[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer for position " << (i + 1) << ": ";
        }
    }

    // No sorting allowed here
    int d = countDescents(a);

    cout << "Part B Analysis (NO SORTING):\n";
    cout << "Descents = " << d << " out of 49\n";

    if (d >= WORST_DESCENTS) cout << "Classification: WORST CASE\n";
    else cout << "Classification: AVERAGE CASE\n";
}

int main() {
    cout << "Running Part A...\n";
    partA();

    cout << "Running Part B...\n";
    partB();

    return 0;
}
