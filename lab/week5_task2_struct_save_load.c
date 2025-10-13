#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define FILENAME "student.txt"

struct Student {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
};

int save_student(const char *filename, const struct Student *student) {
  FILE *file = fopen(filename, "w");
  if (!file) {
    perror("Error opening file for writing");
    return 0;
  }
  fprintf(file, "%s %d %.2f\n", student->name, student->age, student->gpa);
  fclose(file);
  return 1;
}

int load_student(const char *filename, struct Student *student) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Error opening file for reading");
    return 0;
  }
  if (fscanf(file, "%99s %d %f", student->name, &student->age, &student->gpa) !=
      3) {
    fclose(file);
    fprintf(stderr, "Error reading student data from file\n");
    return 0;
  }
  fclose(file);
  return 1;
}

int main() {
  struct Student original = {"Alice", 21, 3.75};
  struct Student loaded;

  printf("Saving student to file...\n");
  if (!save_student(FILENAME, &original)) {
    return 1;
  }

  printf("Loading student from file...\n");
  if (!load_student(FILENAME, &loaded)) {
    return 1;
  }

  printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age,
         loaded.gpa);
  return 0;
}
