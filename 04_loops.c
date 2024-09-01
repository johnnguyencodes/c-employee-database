#include <stdio.h>

#define MAX_IDS 32

int main() {
  int ids[MAX_IDS] = {0};

  int i = 0;
 
  // for loop
  for (i = 0; i < MAX_IDS; i++) {
    ids[i] = i*i;
    printf("%d: %d\n", i, ids[i]);
  }

  // while loop
  i = 0;
  while(i < MAX_IDS) {
    ids[i] = i*i;
    printf("%d: %d\n", i, ids[i]);
    i++;
  }

  // do/while loop
  i = 0;
  do {
    ids[i] = i*i;
    printf("%d: %d\n", i, ids[i]);
    i++;
  } while (i < MAX_IDS);
}
