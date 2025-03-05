#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void ElementMerger(int arr[], int arrLength) {
  while (arrLength > 1) {
    for (int i = 0; i < arrLength; i++) {
      arr[i] = abs(arr[i + 1] - arr[i]);
    }
    arrLength   --;
  }

  printf("%d", arr[0]);
}

// keep this function call here
int main(void) { 
   
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  ElementMerger(A, arrLength);
  return 0;

}