#include <stdio.h>
#define NMAX 30

void input(int *a, int *n, int *out);
// void output_result(int *a, int n);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
  int buffer[NMAX], length, out;
  int number = 0, *numbers = buffer;
  input(buffer, &length, &out);
  if (out == 1) {
    find_numbers(buffer, length, number, numbers);
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
/*void output_result(int *a, int n) {
  for (int *p = a; p - a < n; p++) {
    *p = *p + 1;
    if (p - a < n - 1) {
      printf("%d ", *p);
    }
    if (p - a == n - 1) {
      printf("%d\n", *p);
    }
  }
}*/

int sum_numbers(int *buffer, int length) {  // OK!
  int sum = 0;
  for (int i = 1; i < length; i++) {
    if (buffer[i] % 2 == 0 && buffer[i] != 0) {
      sum = sum + buffer[i];
    }
  }
  return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
  int sum = sum_numbers(buffer, length);
  number = 0;
  // printf("%d\n", sum);
  for (int i = 0; i < length; i++) {
    if (sum % buffer[i] == 0) {
      numbers[number] = buffer[i];
      number++;
    }
  }
  for (int j = 0; j < number; j++) {
    printf("%d ", numbers[j]);
  }
  return number;
}