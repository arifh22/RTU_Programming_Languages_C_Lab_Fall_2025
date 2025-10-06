#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, *arr = NULL;
  long sum = 0;
  double avg = 0.0;

  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid input. Exiting.\n");
    return 1;
  }

  arr = (int *)malloc(n * sizeof(int));
  if (!arr) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("Enter %d integers: ", n);
  for (int i = 0; i < n; ++i) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("Invalid input. Exiting.\n");
      free(arr);
      return 1;
    }
    sum += arr[i];
  }

  avg = n ? ((double)sum / n) : 0.0;

  printf("Sum = %ld\n", sum);
  printf("Average = %.2f\n", avg);

  free(arr);
  return 0;
}