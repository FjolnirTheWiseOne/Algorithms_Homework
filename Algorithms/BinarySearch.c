#include <stdio.h>
#include <stdbool.h>

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

int binarySearch(int array[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}


int main(void) {
  int arr[] = {1, 4, 5, 6, 7, 23, 53, 24, 6345, 345, 666, 25367, 254, 252};
  int sizeOfArray = sizeof(arr) / sizeof(arr[0]);
  int x = 666;
  
  bubbleSort(arr, sizeOfArray);
  int result = binarySearch(arr, x, 0, sizeOfArray - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element %d is found at index %d", x, result);
  return 0;
}