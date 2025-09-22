#include <stdio.h>

int sumton(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main() {
  int n;
  printf("enter a positive integer n: ");
  if (scanf("%d", &n) != 1) {
    printf("its invalid, input:\n");
    return 1;
  }
  if (n < 1) {
    printf("Error: n must be >= 1.\n");
    return 1;
  }
  int result = sumton(n);
  printf("Sum of integers from 1 to %d is %d\n", n, result);
  return 0;
}
