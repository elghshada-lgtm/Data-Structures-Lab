Here is my code: 
``` cpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct CountResult {
    long long comparisons = 0; // counts only: A[j] > key
    long long shifts = 0;      // counts only: A[j+1] = A[j]
    vector<int> finalArray;
};

// Insertion sort that starts at a custom i (startI), and counts comparisons/shifts
CountResult insertionSortCount(vector<int> arr, int startI) {
    CountResult res;

    int n = (int)arr.size();
    for (int i = startI; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // We count ONLY comparisons of the form (arr[j] > key)
        // and shifts of the form arr[j+1] = arr[j]
        while (j >= 0) {
            res.comparisons++;               // A[j] > key is being checked
            if (arr[j] > key) {
                arr[j + 1] = arr[j];        // shift
                res.shifts++;
                j--;
            } else {
                break;
            }
        }

        // Insert key
        arr[j + 1] = key;
    }

    res.finalArray = arr;
    return res;
}

bool containsX_original(const string& s) {
    bool foundX = false;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'X') {
            foundX = true;
        }
    }
    return foundX;
}

bool containsX_improved(const string& s) {
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'X') {
            return true; // early exit
        }
    }
    return false;
}

void printVector(const vector<int>& a) {
    cout << "[ ";
    for (int x : a) cout << x << " ";
    cout << "]";
}

int main() {
    vector<int> worst = {5, 4, 3, 2, 1};

    cout << "Worst-case array (descending): ";
    printVector(worst);
    cout << "\n\n";

    // (a) start i = 1, total should be 20
    auto r1 = insertionSortCount(worst, 1);
    cout << "Insertion sort starting at i = 1\n";
    cout << "Sorted? Output array: ";
    printVector(r1.finalArray);
    cout << "\nComparisons: " << r1.comparisons
         << "\nShifts: " << r1.shifts
         << "\nTotal operations: " << (r1.comparisons + r1.shifts) << "\n\n";

    // (b) start i = 2, then i = 3
    auto r2 = insertionSortCount(worst, 2);
    cout << "Insertion sort starting at i = 2\n";
    cout << "Output array: ";
    printVector(r2.finalArray);
    cout << "\nComparisons: " << r2.comparisons
         << "\nShifts: " << r2.shifts
         << "\nTotal operations: " << (r2.comparisons + r2.shifts) << "\n\n";

    auto r3 = insertionSortCount(worst, 3);
    cout << "Insertion sort starting at i = 3\n";
    cout << "Output array: ";
    printVector(r3.finalArray);
    cout << "\nComparisons: " << r3.comparisons
         << "\nShifts: " << r3.shifts
         << "\nTotal operations: " << (r3.comparisons + r3.shifts) << "\n\n";

    // Task 3: containsX
    cout << "containsX original tests:\n";
    cout << "HELLO -> " << (containsX_original("HELLO") ? "true" : "false") << "\n";
    cout << "BOXXER -> " << (containsX_original("BOXXER") ? "true" : "false") << "\n\n";

    cout << "containsX improved tests:\n";
    cout << "HELLO -> " << (containsX_improved("HELLO") ? "true" : "false") << "\n";
    cout << "XCODE -> " << (containsX_improved("XCODE") ? "true" : "false") << "\n";

    return 0;
}
