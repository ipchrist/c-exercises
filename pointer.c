#include <stdio.h>

int main() {
  int x = 45;
  int *p = &x;
  printf("%d\n%d\n", *p, x);
  *p = 23;
  printf("%d\n%d\n", *p, x);
}
