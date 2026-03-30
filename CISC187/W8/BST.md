Shada Elghariani

CISC 187

W8/Binary Search Trees


## Q1. Draw a diagram showing what the binary search tree would look like.
[1, 5, 9, 2, 4, 10, 6, 3, 8]

```
1
 \
  5
 / \
2   9
 \  / \
  4 6 10
 /     \
3       8
```
## Q2. If a well-balanced binary search tree contains 1,000 values, what is the maximum number of steps it would take to search for a value within it?
Short answer for this question would be 10 steps all together. Long answer is because a balanced BST has an estimated height of log base 2(n). SInce we have 100 values, we would do log base 2 (1000) and we would get an estimated maximum of 10 steps.

## Q3. Write an algorithm that finds the greatest value within a binary search tree.
In binary search trees, the best way to find the greatest value is by using the rightmost nod.
```
Algorithm FindGreatest(root):
1. If root is null → return "tree is empty"
2. Set current = root
3. While current.right is not null:
4.     current = current.right
5. Return current.value
```
## Q4: Write a code in C++ using the same array mentioned in #1 and implement a binary search tree. Only insertion operation is required.

```
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

int main() {
    Node* root = nullptr;

    int arr[] = {1, 5, 9, 2, 4, 10, 6, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    cout << "BST was constructed successfully." << endl;

    return 0;
}
```
