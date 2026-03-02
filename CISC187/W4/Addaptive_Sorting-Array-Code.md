Here is the code:
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
