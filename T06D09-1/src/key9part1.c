/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(const int *buffer, int length) {
    int sum = 0;
    for (int i = 1; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int sum = sum_numbers(buffer, length);
    number = 0;
    for (int i = 0; i < length; i++) {
        if (sum % buffer[i] == 0) {
            numbers[number] = buffer[i];
            number++;
        }
    }
}
