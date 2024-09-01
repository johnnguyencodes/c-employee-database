#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 1000



struct employee_t {
  int id;
  int hourly_rate;
  bool staff;
};

int initialize_employee(struct employee_t *pE) {
  // the static keyword will initialize this variable in global scope, but only we have access to it
  // Every time the function gets called, this variable doesn't change its value
  static int num_employees = 0;

  // every time the function runs, we can increment it and its value will not reset.
  // By creating a static variable, we are able to create variables that out live the lifetime 
  // of a function call and track data over multiple calls to the same function.
  // This variable lives in what's called the data section of the ELF, it doesn't get destroyed
  // when the function returns.
  // This is called data hiding, other functions can't access this variable to prevent race conditions
  num_employees++;

  pE->id = num_employees;
  pE->hourly_rate = 0;
  pE->staff = false;

  return num_employees;
}

int main() {
  // employees will turn into a pointer
  // This pointer can point to an infinite number of elements further out from the base element
  // Set the pointer equal to malloc, the memory allocator. We are asking LibC to return to us a pointer to some size (amount) of memory
  // How much memory do we want? We want the memory size of one struct employee_t * the number of employees that we want
  // struct employee_t *employees = malloc(sizeof(struct employee_t)*MAX_EMPLOYEES);
  // But instead of using some gigantic constant, we can actually use a runtime value. 
  // Normally this value will come from the database header
  int n = 4;
  // Using `n`, we can allocate only the amount of employees that we need.
  struct employee_t *employees = malloc(sizeof(struct employee_t)*n);
  // It's good practice to make sure that you check that your pointer did not get null returned, because sometimes the memory allocator can fail
  if (employees == NULL) {
    // And if it returns null, we don't want to use that memory because we can't dereference null to get the actual value.  
    printf("The memory allocator failed\n");
    // -1 is bad error code, letting us know the code failed
    return -1;
  }
  for (int i = 0; i < n; i++) {
    int id = initialize_employee(&employees[i]);
    printf("New employee, ID is %d\n", id);
  }

  // Once the code is done, we need to give the memory back to the memory allocator
  // So we can avoid what is called a memory leak
  // Where the memory in your code is not given back to the operating system.
  // And over time you can actually allocate all the virtual memory allowed for your process
  // And the kernel will end up killing your process.
  // Once we are done using the memory run the following line so we can give the employees value back to the allocator
  free(employees);
  // Also need to set employees equal to null.  If the pointer is freed and given back to the allocator
  // We don't want to enable ourselves to use it.  This is what would've been called a `use after free`
  // It's a huge set of bugs that create memory corruption vulnerabilities in code. 
  employees = NULL;
  // By freeing the memory and deleting the pointer we give oursleves, we remove ourselves the power
  // Of being able to accidentally use it the future, or else we can crash the program.  
  printf("%d\n", employees[0].id);
}
