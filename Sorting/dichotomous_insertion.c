// Dichotomous insertion sorting
// Or Binary Insertion sort in C
#include <stdio.h>

// Binary Search
int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    // Get position of middle element
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

int main() {
    //test array
    int test[] = {-23, 45, 6, 0, 234, -3, 9};
    //getting size of array
    int size = sizeof(test) / sizeof(test[0]);
    
}