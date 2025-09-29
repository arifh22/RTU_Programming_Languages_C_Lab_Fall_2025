#include <stdio.h>

int LengthOfString(const char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

void copyOfString(char *dest, const char *src) {
  while (*src) {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
}

int main() {
  char text[] = "hello";
  int len = my_strlen(text);

  char buffer[100];
  copyOfString(buffer, text);
  printf("Length: %d\n", len);
  printf("Copied string: %s\n", buffer);

  return 0;
}