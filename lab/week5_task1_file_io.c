#include <stdio.h>
#include <stdlib.h>

#define FILENAME "data.txt"
#define MAX_LINE_LEN 256
#define NUM_LINES 3

int main(void) {
  FILE *fp;
  char buffer[MAX_LINE_LEN];
  const char *lines[NUM_LINES] = {
      "Exploring file operations in C language.\n",
      "This line is distinct, crafted for this example.\n",
      "Demonstrating reading and writing without repetition.\n"};

  printf("Writing lines to %s...\n", FILENAME);
  fp = fopen(FILENAME, "w");
  if (fp == NULL) {
    perror("Error opening file for writing");
    return 1;
  }
  for (int i = 0; i < NUM_LINES; ++i) {
    if (fprintf(fp, "%s", lines[i]) < 0) {
      fprintf(stderr, "Failed to write line %d\n", i + 1);
      fclose(fp);
      return 1;
    }
  }
  fclose(fp);

  printf("Reading contents:\n");
  fp = fopen(FILENAME, "r");
  if (fp == NULL) {
    perror("Error opening file for reading");
    return 1;
  }
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
  }
  fclose(fp);

  return 0;
}