// Quick Sort in C
#include <stdio.h>

//swap function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b =temp;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high) {
  
  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // Select pivot position and put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pos = partition(array, low, high);
    
    // Sort the elements on the left of pivot
    quickSort(array, low, pos - 1);
    
    // Sort the elements on the right of pivot
    quickSort(array, pos + 1, high);
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
    quickSort(test, 0, size - 1);
    printf("Sorted array in ascending order:\n");
    printArray(test, size);
    
}