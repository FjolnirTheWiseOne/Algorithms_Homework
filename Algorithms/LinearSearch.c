#include <stdio.h>

int linearSearch(int array[], int n, int x) {
    
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main() {
  int arr[] = {1, 4, 5, 6, 7, 23, 53, 24, 6345, 666, 256, 25367, 254, 252};

  int x = 666;
  int n = sizeof(arr) / sizeof(arr[0]);

  int result = linearSearch(arr, n, x);

  (result == -1) ? printf("Element not found") : printf("Element found at index: %d", result);
}