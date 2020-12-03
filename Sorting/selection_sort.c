
#include <stdio.h>

//swap function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b =temp;
}

void selectionSort (int array[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(array[i]>array[j])
                swap(&array[i], &array[j]);
        }
    }
}

void displayArray(int array[], int size){
    for (int i=0; i<size; i++){
        printf("%d \t", array[i]);
    }
}

int main(){
    int arr[] = {101, 115, 30, 63, 47, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting \n");
    displayArray(arr, size);
    selectionSort(arr, size);
    printf("\n");
    printf("After sorting \n");
    displayArray(arr, size);
    return 0;
}
