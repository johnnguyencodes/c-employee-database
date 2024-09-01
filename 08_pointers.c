#include <stdio.h>
#include <stdbool.h>

struct employee_t {
  int id;
  int hourly_rate;
  bool staff;
};

// if the employee is declared in the `main` variable scope, `initialize_employee` can't access it. 
// This is where pointers come in. Pass variables as function arguments by passing a reference to its memory address.  
void initialize_employee(struct employee_t *pE) {
  pE->id = 0;
  pE->hourly_rate = 0;
  pE->staff = false;

  return;
}

int main() {
  int x = 3;
  // create an integer pointer, whose name is pX, and set its value to the memory address of x.
  int *pX = &x;

  // In order to get to the value pointed to by pX, I will dereference (turn a reference to a value) pX which is pointed to x.
  // *pX literally says get the value pointed to by pX
  printf("Get me the value, %d \n", *pX);
  // I want to get the pointer value of pX, which is the memory address of x.
  printf("Get me the pointer value, %p \n", pX);

  // 

  // setting the default value for Ralph
  struct employee_t Ralph;
  // Ralph.id = 1;
  // Ralph.hourly_rate = 0;

  // How do we get a pointer from Ralph?
  // We just pass in the address of Ralph with &
  initialize_employee(&Ralph);
  printf("%d\n", Ralph.hourly_rate);
  
  return 0;
}
