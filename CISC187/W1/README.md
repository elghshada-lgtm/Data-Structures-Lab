# Data-Structures-Lab
# Array Data Structure in C++

## Creating an Array of 100 Elements
I created an integer array that can store 100 values of the same data type in memory.

## Size of Each Element
Using sizeof() to find how many bytes one array element takes in memory.
The code shows us that in one element there is 4 bytes.

## Steps for Operations (N = 100)

| Operation                | Steps |
|--------------------------|-------|
| Reading                  | 1     |
| Searching (not in array) | N     |
| Insert at beginning      | N+1   |
| Insert at end            | 1     |
| Delete at beginning      | N     |
| Delete at end            | 1     |

## Counting All "Apple" Values
To find all instances of "apple", the array must be scanned completely.
Steps = N  
Time Complexity = O(N)

## Finding Memory Address of an Array
To find this part, you need to print the memory 
address of the array to show where it is stored in RAM.
Look back at the code to see the idea.
