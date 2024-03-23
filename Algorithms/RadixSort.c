#include <stdio.h>

int getMaxValue(int array[], int n){
    int max = array[0];
    for(int i = 1; i < n; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

void countingSort(int array[], int sizeOfArray, int place) {
  int output[sizeOfArray + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < sizeOfArray; i++) {
    if (((array[i] / place) % 10) > max){
      max = array[i];
    }
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < sizeOfArray; i++)
    count[(array[i] / place) % 10]++;
    
  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = sizeOfArray - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }
}
void radixSort(int array[], int sizeOfArray){
    int max = getMaxValue(array, sizeOfArray);
    for(int place = 1; max / place > 0; place *= 10){
        countingSort(array, sizeOfArray, place);
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
    radixSort(arr, size);
    printArray(arr, size);
    
    return 0;
}
