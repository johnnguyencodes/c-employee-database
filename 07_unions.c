#include <stdio.h>
#include <stdbool.h>

// union will create enough room for the biggest element, in this case most likely int x
// also allowed access to all the sub elements by using u.x
union my_union_u {
  int x;
  char c;
  short s;
};

int main() {

  union my_union_u u;
  // this is the hexadecimal represents the ASCII characters "A", "B", "C", "D"
  u.x = 0x41424344;

  printf("%hx %hhx\n", u.s, u.c);
  // %hx will get us the second half of the hexadecimal `4344`, and %hhx will give us half of half, in this case `44`
  // The reason why %hx gets us the second half instead of the first half is due to the way data is stored in memory on the current system (endianness).
  // On little-endian systems, the least significant bye is stored at the lowest memory address.  For example, the integer `0x41424344` would be stored in memory as `44 43 42 41`. 
  // To get the first half `4142`, you need to access the higher memory address where these bytes are stored. A way to do this is to shift the data down by 16 bits, or two bytes

  // Example of getting both halves
  
  // Print the second half (lower 2 bytes)
  printf("Lower half: %hx\n", u.s); // Prints "4344"

  // Print the first half (upper 2 bytes)
  printf("Upper half: %hx\n", (u.x >> 16)); // Prints "4142"

  // Print the first quarter
  printf("First quarter: %hhx\n", (u.x >> 24)); // Prints "41"
}
