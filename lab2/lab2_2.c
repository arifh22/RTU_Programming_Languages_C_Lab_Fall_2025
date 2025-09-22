#include <stdio.h>

long long factrl(int n) {
  long long result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main() {
  int n;
  printf("enter integer which is not negative n: ");
  if (scanf("%d", &n) != 1) {
    printf("invalid input.\n");
    return 1;
  }
  if (n < 0) {
    printf("error: n must be >= 0.\n");
    return 1;
  }
  long long result = factrl(n);
  printf("Factorial of %d is %lld\n", n, result);
  return 0;
}
