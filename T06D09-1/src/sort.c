#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int sort(int *a, int n);
void output(int *a, int n);

int main() {
  int n = 10, data[NMAX];
  if (input(data, &n) == 0) {
    printf("n/a");
  } else {
    sort(data, n);
    output(data, n);
  }
}
int input(int *a, int *n) {
  for (int *p = a; p - a < *n; p++) {
    if (scanf("%d", p) == 0) return 0;
  }
  if (getchar() != '\n') return 0;
  return 1;
}
int sort(int *a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] > a[j + 1]) {
        int b = a[j];
        a[j] = a[j + 1];
        a[j + 1] = b;
      }
    }
  }
  return 1;
}
void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    if (i < n - 1) {
      printf("%d ", a[i]);
    } else {
      printf("%d", a[i]);
    }
  }
}
