#include <stdio.h>
#define NMAX 10

void input(int *a, int *n, int *out);
void output_result(int *a, int n);

int main() {
  int n, out, data[NMAX];
  input(data, &n, &out);
  if (out == 1) {
    output_result(data, n);
  } else {
    printf("n/a");
  }
  return 0;
}

void input(int *a, int *n, int *out) {
  if (!scanf("%d", n) || *n <= 0 || *n > NMAX || getchar() != '\n') {
    *out = 0;
  } else {
    for (int *p = a; p - a < *n; p++) {
      if (scanf("%d", p) == 0) {
        *out = 0;
        break;
      }
      *out = 1;
    }
  }
}
void output_result(int *a, int n) {
  for (int *p = a; p - a < n; p++) {
    *p = *p + 1;
    if (p - a < n - 1) {
      printf("%d ", *p);
    }
    if (p - a == n - 1) {
      printf("%d\n", *p);
    }
  }
}
