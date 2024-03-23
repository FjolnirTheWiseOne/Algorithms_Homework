#include <stdio.h>


void countingSort(int array[], int sizeOfArray){
    int output[20];
    
    int max = array[0];
    for(int i = 1; i < sizeOfArray; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    int count[max + 1];
    
    for(int i = 0; i <= max; i++){
        count[i] = 0;
    }
    
    for(int i = 0; i < sizeOfArray; i++){
        count[array[i]]++;
    }
    
    for(int i = 1; i <= max; i++){
        count[i] += count[i - 1];
    }
    for(int i = sizeOfArray - 1; i >= 0; i--){
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for(int i = 0; i < sizeOfArray; i++){
        array[i] = output[i];
    }
    
} 

void printArray(int array[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 4, 5, 6, 7, 23, 53, 24, 6345, 345, 256, 25367, 254, 252};
    int size = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, size);
    printArray(arr, size);
    
    return 0;
}
