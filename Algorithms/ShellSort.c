#include <stdio.h>


void shellSort(int array[], int sizeOfArray){
    for(int interval = sizeOfArray/2; interval > 0; interval /= 2){
        for(int i = interval; i < sizeOfArray; i++){
            int temp = array[i];
            int j;
            for(j = i; j >= interval && array[j - interval] > temp; j -= interval){
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
} 

void printArray(int array[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
}

int main()
{
    int arr[] = {1, 4, 5, 6, 7, 23, 53, 24, 6345, 345, 256, 25367, 254, 252};
    int size = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, size);
    printArray(arr, size);
    
    return 0;
}
