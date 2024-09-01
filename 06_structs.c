#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_IDS 32
#define MAX_EMPLOYEES 1000

// the attribute below is a special struct modifier that ensures the 
// compiler doesn't add any special information between the elements
// so it's the same size on multiple platforms
__attribute__((__packed__)) struct employee_t {
  int id;
  char first_name[64];
  char last_name[64];
  float hourly_rate;
  bool is_manager;
};

struct Employee {
  int id;
  char name[64];
  int age;
};

int main(int argc, char **argv) {
  // creating an array of employees
  struct employee_t employees[MAX_EMPLOYEES];

  int i = 0;
  for (i = 0; i < MAX_EMPLOYEES; i++) {
    employees[i].hourly_rate = 0;
    employees[i].is_manager = false;
  };

  printf("%f\n", employees[10].hourly_rate);
  printf("Size of employee: %d\n", sizeof(struct employee_t));

  // creating a new employee struct named emp 
  struct Employee emp = {
    .name = "Steve",
    .age = 42
  };

  printf("%s, aged %d years\n", emp.name, emp.age);

  return 0;
}
