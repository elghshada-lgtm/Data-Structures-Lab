Here is my code for this project:
``` cpp

#include <iostream>
using namespace std;

// print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// bubble sort
int bubbleSort(int arr[], int size) {
    int steps = 0;
    int a[size];
    for(int i=0; i < size; i++) a[i] = arr[i];

    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            steps++; // comparison
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                steps++; // swap
            }
        }
    }
    cout << "Bubble sorted: ";
    printArray(a, size);
    return steps;
}

// selection sort
int selectionSort(int arr[], int size) {
    int steps = 0;
    int a[size];
    for(int i=0; i < size; i++) a[i] = arr[i];

    for(int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for(int j = i+1; j < size; j++) {
            steps++; // comparison
            if(a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        if(minIdx != i) {
            int temp = a[i];
            a[i] = a[minIdx];
            a[minIdx] = temp;
            steps++;
        }
    }
    cout << "Selection sorted: ";
    printArray(a, size);
    return steps;
}

// insertion sort
int insertionSort(int arr[], int size) {
    int steps = 0;
    int a[size];
    for(int i=0; i < size; i++) a[i] = arr[i];

    for(int i = 1; i < size; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0) {
            steps++; // comparison
            if(a[j] > key) {
                a[j+1] = a[j];
                steps++; // move
                j--;
            } else {
                break;
            }
        }
        a[j+1] = key;
    }
    cout << "Insertion sorted: ";
    printArray(a, size);
    return steps;
}

int main() {
    int arr[] = {8, 3, 5, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    int bubbleSteps = bubbleSort(arr, size);
    cout << "Bubble Sort steps: " << bubbleSteps << "\n\n";

    cout << "Original array: ";
    printArray(arr, size);

    int selectionSteps = selectionSort(arr, size);
    cout << "Selection Sort steps: " << selectionSteps << "\n\n";

    cout << "Original array: ";
    printArray(arr, size);

    int insertionSteps = insertionSort(arr, size);
    cout << "Insertion Sort steps: " << insertionSteps << endl;

    return 0;
}
