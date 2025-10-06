#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 64

struct Student {
  int id;
  char name[NAME_LEN];
  float grade;
};

void print_table(struct Student *students, int count) {
  printf("\n%-8s%-12s%-8s\n", "ID", "Name", "Grade");
  for (int i = 0; i < count; ++i) {
    printf("%-8d%-12s%-8.2f\n", students[i].id, students[i].name,
           students[i].grade);
  }
}

int main() {
  int n;
  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  struct Student *students = malloc(n * sizeof(struct Student));
  if (!students) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < n; ++i) {
    printf("Enter data for student %d (name id grade): ", i + 1);
    if (scanf("%63s %d %f", students[i].name, &students[i].id,
              &students[i].grade) != 3) {
      printf("Invalid input.\n");
      free(students);
      return 1;
    }
  }

  print_table(students, n);

  free(students);
  return 0;
}