#include <stdbool.h>
#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = * yp;
    *yp = temp;
}

void bubbleSort(int arr[], int size){
    bool swapped;
    int i, j;
    for(i = 0; i < size - 1; i++){
        swapped = false;
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
}
void printArray(int arr[], int razmer){
    for(int i = 0; i < razmer; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = { 2, 4, 5, 3, 1, 5, 6, 1, 3, 5};
    int size = sizeof(arr) / (sizeof(arr[0]));
    bubbleSort(arr, size);
    printArray(arr, size);
    
    return 0;
}