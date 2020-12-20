void bubbleSort(int array[], int size) {
  for (int i = 0; i < size - 1; ++i) {

    // To keep track of swapping
    int swapped = 0;

    // First loop to move through array
    for (int i = 0; i < size - i - 1; ++i) {

      // This loop is for the comparison
      // Change > to < in this line to sort according.
      if (array[i] > array[i + 1]) {
        
        // Swap if first element is greater than the next
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = 1;
      }
    }

    // If there is not swapping in the last swap, then the array is already sorted.
    if (swapped == 0)
      break;
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
    bubbleSort(test, size);
    printf("Sorted Array in Ascending Order:\n");
    printArray(test, size);
}