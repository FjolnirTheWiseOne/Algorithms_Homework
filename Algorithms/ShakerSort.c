#include <stdbool.h>
#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void shakerSort(int array[], int sizeOfArray){
    bool swapped = true;
    int start = 0;
    int end = sizeOfArray - 1;
    
    while (swapped) {
        swapped = false;
        
        for(int i = start; i < end; i++){
            if(array[i] > array[i + 1]){
                swap(&array[i], &array[i + 1]);
                swapped = true;
            }
        }
        
        if (!swapped){
            break;
        }
        
        swapped = false;
        
        --end;
        for(int i = end - 1; i >= start; --i){
            if(array[i] > array[i + 1]){
                swap(&array[i], &array[i + 1]);
                swapped = true;
            }
                
        }
        ++start;
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
    shakerSort(arr, size);
    printArray(arr, size);
    
    return 0;
}
