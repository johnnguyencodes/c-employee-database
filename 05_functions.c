#include <stdio.h>

// return_type name(list of arguments) {
//
// }

int add(int x, int y) {
  int z = x + y;

  return z;
}

// int initialize_employee_structure(Employee *e) {
  // initialize a stucture to
  // contain employee data
  //
// }

int main(int argc, char *argv[]) {
  int other_int = add(1,2);
  printf("%d\n", other_int);

  return 0;
}
