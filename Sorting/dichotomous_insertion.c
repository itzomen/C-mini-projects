// Dichotomous insertion sorting
// Or Binary Insertion sort in C
#include <stdio.h>

// Binary Search
int binarySearch(int array[], int x, int low, int high) {
  //if (high >= low)
  if (high <= low)
        return (x > array[low]) ? (low + 1) : low;

    // Get position of middle element
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid + 1;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);

}

// Insertion Sort
void insertionSort(int array[], int size) {
    int pos, j, k;

    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        pos = binarySearch(array, key, 0, j);

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (j >= pos) {
        array[j + 1] = array[j];
        --j;
        }
        array[j + 1] = key;
    }
}

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
    //test array
    int test[] = {-23, 45, 6, 0, 234, -3, 9};
    //getting size of array
    int size = sizeof(test) / sizeof(test[0]);
    printf("UnSorted Array:\n");
    printArray(test, size);
    //Sorting
    insertionSort(test, size);
    printf("Sorted array in ascending order:\n");
    printArray(test, size);
    
}