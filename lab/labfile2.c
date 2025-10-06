#include <stdio.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

void print_student(const struct Student *s, int number) {
  printf("Student %d: %s, ID: %d, Grade: %.2f\n", number, s->name, s->id,
         s->grade);
}

int main() {
  struct Student student1, student2;

  strcpy(student1.name, "Alice Johnson");
  student1.id = 1001;
  student1.grade = 9.1f;

  struct Student temp = {"Bob Smith", 1002, 8.7f};
  student2 = temp;

  print_student(&student1, 1);
  print_student(&student2, 2);

  return 0;
}