#include <stdio.h>

int main() {
  int temp;
  printf("What temperature is it?\n");
  scanf("%d", &temp);

  if (temp >= 70) {
    printf("dang it's hot\n");
  } else if (temp >= 30 && temp < 70) {
    printf("it's mild\n");
  } else {
    printf("it's cold\n");
  }

  return 0;
}
