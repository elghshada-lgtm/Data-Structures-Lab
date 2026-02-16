## Here is my code for Search Lab:
```cpp

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

// Linear Search
int linearSearch(const vector<int>& arr, int key) {
    int steps = 0;
    for (int x : arr) {
        steps++;
        if (x == key) return steps;
    }
    return steps;
}

// Binary Search
int binarySearch(const vector<int>& arr, int key) {
    int steps = 0;
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return steps;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return steps;
}

// Randomized Search without repetition
int randomizedSearch(const vector<int>& arr, int key) {
    vector<int> indices(arr.size());
    for (int i = 0; i < (int)arr.size(); i++) indices[i] = i;

    random_device rd;
    mt19937 g(rd());
    shuffle(indices.begin(), indices.end(), g);

    int steps = 0;
    for (int i : indices) {
        steps++;
        if (arr[i] == key) return steps;
    }
    return steps;
}

int main() {
    const int N = 100000;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) arr[i] = i + 1;

    sort(arr.begin(), arr.end());

    int key;
    cout << "Enter a number to search (1 to 100000): ";
    cin >> key;

    int stepsLinear = linearSearch(arr, key);
    int stepsBinary = binarySearch(arr, key);
    int stepsRandom = randomizedSearch(arr, key);

    cout << "\n--- Search Results ---\n";
    cout << "Linear Search steps: " << stepsLinear << endl;
    cout << "Binary Search steps: " << stepsBinary << endl;
    cout << "Randomized Search steps: " << stepsRandom << endl;

    return 0;
}
```
