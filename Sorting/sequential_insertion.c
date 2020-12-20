// This is the normal Insertion sort in C
#include <stdio.h>


void sequentialSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
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
    sequentialSort(test, size);
    printf("Sorted array in ascending order:\n");
    printArray(test, size);
}