#include <stdio.h>

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int div(int x, int y) { return x / y; }
int mul(int x, int y) { return x * y; }
int mod(int x, int y) { return x % y; }

int arithemetic(int (*fn)(int, int), int x, int y) { return fn(x, y); }

int main() {
  printf("%d", arithemetic(&sub, 2, 3));
  return 0;
}
