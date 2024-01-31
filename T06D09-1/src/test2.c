#include <stdio.h>
#define NMAX 30

void input(int *buffer, int *length, int *out);
void output(int *buffer, int *length, int number, int *numbers);
int sum_numbers(int *buffer, int *length);
int find_numbers(int *buffer, int *length, int number, int *numbers);

int main() {
  int buffer[NMAX], length, out;
  int number = 0, *numbers = buffer;
  input(buffer, &length, &out);
  if (out == 1) {
    output(buffer, &length, number, numbers);
  } else {
    printf("n/a");
  }
  return 0;
}

void input(int *buffer, int *length, int *out) {
  if (!scanf("%d", length) || *length <= 0 || *length > NMAX ||
      getchar() != '\n') {
    *out = 0;
  } else {
    for (int *p = buffer; p - buffer < *length; p++) {
      if (scanf("%d", p) == 0) {
        *out = 0;
        break;
      }
      *out = 1;
    }
  }
}
int sum_numbers(int *buffer, int *length) {  // OK!
  int sum = 0;
  for (int i = 0; i < *length; i++) {
    if (buffer[i] % 2 == 0 && buffer[i] != 0) {
      sum = sum + buffer[i];
    }
  }
  return sum;
}

int find_numbers(int *buffer, int *length, int number, int *numbers) {
  int sum = sum_numbers(buffer, length);
  number = 0;
  for (int i = 0; i < *length; i++) {
    if (buffer[i] != 0 && sum % buffer[i] == 0) {
      numbers[number] = buffer[i];
      number++;
    }
  }
  /*for (int i = 0; i < number; i++) {
    if (i < number - 1)
      printf("%d ", numbers[i]);
    else
      printf("%d\n", numbers[i]);
  }*/
  return *numbers;
}
void output(int *buffer, int *length, int number, int *numbers) {
  printf("%d\n", sum_numbers(buffer, length));
  printf("%d", find_numbers(buffer, length, number, numbers));
}