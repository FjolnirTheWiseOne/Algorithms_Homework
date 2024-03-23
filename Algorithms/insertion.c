#include <stdio.h>

void insertionSort(int arr[], int sizeOfArray){
    int i, key, j;
    for(i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] < key){
            arr[j + 1] = arr[j];
            j--; // j = j - 1
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int sizeOfArray){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {1, 9, 8, 7, 5, 3, 25, 243, 52, 2, 295, 339, 666, 666, 666, 666, 666, 666, 66, 66, 6, 6, 6, 6};
    int razmer = sizeof(arr) / sizeof(arr[0]);
    
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}