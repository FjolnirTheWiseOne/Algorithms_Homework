#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = * yp;
    *yp = temp;
}

void selectionSort(int arr[], int size ){
    int i, j, minIndex;
    
    for(i = 0; i < size - 1; i++){
        minIndex = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
            swap(&arr[minIndex], &arr[i]);
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
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}