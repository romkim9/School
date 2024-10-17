#include <stdio.h>
#include <string.h>

struct studentTag{
  char name[10];
  int age;
  double gpa;
};

int main(){
  struct studentTag s;

  strcpy(s.name, "kim");
  s.age = 20;
  s.gpa = 4.3;

  printf("name : %s\nage : %d\ngpa : %f", s.name, s.age, s.gpa);

  return 0;
}
