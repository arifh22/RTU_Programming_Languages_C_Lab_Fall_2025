#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define FILENAME "students.txt"

typedef struct {
  char name[NAME_LEN];
  int id;
  float gpa;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void load_students() {
  FILE *file = fopen(FILENAME, "r");
  if (!file) {
    student_count = 0;
    return;
  }
  student_count = 0;
  while (student_count < MAX_STUDENTS) {
    char line[128];
    if (!fgets(line, sizeof(line), file)) break;

    char name[NAME_LEN];
    int id;
    float gpa;
    if (sscanf(line, "%49[^,],%d,%f", name, &id, &gpa) == 3) {
      strncpy(students[student_count].name, name, NAME_LEN - 1);
      students[student_count].name[NAME_LEN - 1] = '\0';
      students[student_count].id = id;
      students[student_count].gpa = gpa;
      student_count++;
    }
  }
  fclose(file);
}

void save_students() {
  FILE *file = fopen(FILENAME, "w");
  if (!file) {
    printf("Error: Unable to save data.\n");
    return;
  }
  for (int i = 0; i < student_count; i++) {
    fprintf(file, "%s,%d,%.2f\n", students[i].name, students[i].id,
            students[i].gpa);
  }
  fclose(file);
}

void add_student() {
  if (student_count >= MAX_STUDENTS) {
    printf("Student limit reached.\n");
    return;
  }
  Student s;
  printf("Enter name: ");
  if (!fgets(s.name, sizeof(s.name), stdin)) return;
  size_t len = strlen(s.name);
  if (len > 0 && s.name[len - 1] == '\n') s.name[len - 1] = '\0';

  printf("Enter ID: ");
  if (scanf("%d", &s.id) != 1) {
    printf("Invalid ID.\n");
    while (getchar() != '\n');
    return;
  }

  printf("Enter GPA: ");
  if (scanf("%f", &s.gpa) != 1) {
    printf("Invalid GPA.\n");
    while (getchar() != '\n');
    return;
  }
  while (getchar() != '\n');

  students[student_count++] = s;
  printf("Student added successfully!\n");
}

void list_students() {
  if (student_count == 0) {
    printf("No students found.\n");
    return;
  }
  printf("ID\tName\t\tGPA\n");
  printf("---------------------------------\n");
  for (int i = 0; i < student_count; i++) {
    printf("%d\t%-16s\t%.2f\n", students[i].id, students[i].name,
           students[i].gpa);
  }
}

int main() {
  load_students();
  int choice;
  while (1) {
    printf("\n=== Student Management System ===\n");
    printf("1. List students\n");
    printf("2. Add student\n");
    printf("3. Save and Exit\n");
    printf("Select an option: ");
    if (scanf("%d", &choice) != 1) {
      printf("Invalid input.\n");
      while (getchar() != '\n');
      continue;
    }
    while (getchar() != '\n');
    if (choice == 1) {
      list_students();
    } else if (choice == 2) {
      add_student();
    } else if (choice == 3) {
      save_students();
      printf("Data saved. Sagolasan!\n");
      break;
    } else {
      printf("Invalid option. Try again.\n");
    }
  }
  return 0;
}