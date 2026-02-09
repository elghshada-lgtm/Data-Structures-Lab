#include <iostream>
using namespace std;

int main() {
    //Task 1
    int numbers[100];

    cout << "Array of 100 integers created." << endl;

    //Task 2
    cout << "Size of one element: "
         << sizeof(numbers[0]) << " bytes" << endl;

    //Task 5
    cout << "Array base address: " << numbers << endl;
    cout << "First element address: " << &numbers[0] << endl;

    return 0;
}
