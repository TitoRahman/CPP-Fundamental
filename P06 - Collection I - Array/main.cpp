#include <iostream>

using namespace std;

int main() {
    // Pointer -> Address of a variable
    // Reference -> Alias of a variable
    // int  x = 10;
    // int &y = x;
    // y = 20;
    // cout << x << " "<< y << endl;

    // ARRAY -> Collection of similar data types with fixed size
    int *arr = (int*) malloc(2 * sizeof(int));  // store 5 integers in memory

    int var = 10;
    cout << &var << endl;
    int *ptr;
    cout << &ptr << endl;

    arr[0] = 10; 
    arr[1] = 20;
    
    arr = (int*) realloc(arr, 4 * sizeof(int));
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    // int arr2[5] = {10, 20, 30, 40};
    // int arr3[] = {10, 20, 30, 40, 50, 60};

    // Memory Allocation
    //  Malloc -> Memory Allocation
    // int *arr4 = (int*) malloc(n * sizeof(int));
    // malloc (10 * 4) -> 40 bytes -> 10 integers
    // malloc (10 * 1) -> 10 bytes -> 10 characters
    
    //  Calloc -> Contiguous Allocation
    // int *arr5 = (int*) calloc(n, sizeof(int));

    //  Realoc -> Reallocate Memory


    //  Free -> Free Memory

    return 0;
}

