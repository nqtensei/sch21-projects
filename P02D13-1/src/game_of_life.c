#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define XMAX 80
#define YMAX 25

int create_random_matrix(int (*matrix)[XMAX]);
int logic(int (*current_matrix)[XMAX]);
void output(int (*matrix)[XMAX]);

int main() {
    int matrix[YMAX][XMAX];
    int sum = 1;
    create_random_matrix(matrix);
    while (sum != 0) {
        sum = 0;
        output(matrix);
        logic(matrix);
        for (int i = 0; i < YMAX; i++) {
            for (int j = 0; j < XMAX; j++) {
                sum += matrix[i][j];
            }
        }
    }
}
int create_random_matrix(int (*matrix)[XMAX]) {
    for (int i = 0; i < YMAX; i++) {
        for (int j = 0; j < XMAX; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
    return **matrix;
}
int logic(int (*current_matrix)[XMAX]) {
    int future_matrix[YMAX][XMAX];
    for (int i = 0; i < YMAX; i++) {
        for (int j = 0; j < XMAX; j++) {
            int neigh = 0;
            if (i == 0 && j == 0) {
                if (current_matrix[24][79] == 1) neigh++;
                if (current_matrix[24][j] == 1) neigh++;
                if (current_matrix[24][j + 1] == 1) neigh++;
                if (current_matrix[i][79] == 1) neigh++;
                if (current_matrix[i][j + 1] == 1) neigh++;
                if (current_matrix[i + 1][79] == 1) neigh++;
                if (current_matrix[i + 1][j] == 1) neigh++;
                if (current_matrix[i + 1][j + 1] == 1) neigh++;
            }
            if (i == 0 && (j > 0 && j < 79)) {
                if (current_matrix[24][j - 1] == 1) neigh++;
                if (current_matrix[24][j] == 1) neigh++;
                if (current_matrix[24][j + 1] == 1) neigh++;
                if (current_matrix[i][j - 1] == 1) neigh++;
                if (current_matrix[i][j + 1] == 1) neigh++;
                if (current_matrix[i + 1][j - 1] == 1) neigh++;
                if (current_matrix[i + 1][j] == 1) neigh++;
                if (current_matrix[i + 1][j + 1] == 1) neigh++;
            }
            if (i == 0 && j == 79) {
                if (current_matrix[24][j - 1] == 1) neigh++;
                if (current_matrix[24][j] == 1) neigh++;
                if (current_matrix[24][0] == 1) neigh++;
                if (current_matrix[i][j - 1] == 1) neigh++;
                if (current_matrix[i][0] == 1) neigh++;
                if (current_matrix[i + 1][j - 1] == 1) neigh++;
                if (current_matrix[i + 1][j] == 1) neigh++;
                if (current_matrix[i + 1][0] == 1) neigh++;
            }
            if (j == 0 && (i > 0 && i < 24)) {
                if (current_matrix[i - 1][79] == 1) neigh++;
                if (current_matrix[i - 1][j] == 1) neigh++;
                if (current_matrix[i - 1][j + 1] == 1) neigh++;
                if (current_matrix[i][79] == 1) neigh++;
                if (current_matrix[i][j + 1] == 1) neigh++;
                if (current_matrix[i + 1][79] == 1) neigh++;
                if (current_matrix[i + 1][j] == 1) neigh++;
                if (current_matrix[i + 1][j + 1] == 1) neigh++;
            }
            if (j == 79 && (i > 0 && i < 24)) {
                if (current_matrix[i - 1][j - 1] == 1) neigh++;
                if (current_matrix[i - 1][j] == 1) neigh++;
                if (current_matrix[i - 1][0] == 1) neigh++;
                if (current_matrix[i][j - 1] == 1) neigh++;
                if (current_matrix[i][0] == 1) neigh++;
                if (current_matrix[i + 1][j - 1] == 1) neigh++;
                if (current_matrix[i + 1][j] == 1) neigh++;
                if (current_matrix[i + 1][0] == 1) neigh++;
            }
            if ((i > 0 && i < 24) && (j > 0 && j < 79)) {
                if (current_matrix[i - 1][j - 1] == 1) neigh++;
                if (current_matrix[i - 1][j] == 1) neigh++;
                if (current_matrix[i - 1][j + 1] == 1) neigh++;
                if (current_matrix[i][j - 1] == 1) neigh++;
                if (current_matrix[i][j + 1] == 1) neigh++;
                if (current_matrix[i + 1][j - 1] == 1) neigh++;
                if (current_matrix[i + 1][j] == 1) neigh++;
                if (current_matrix[i + 1][j + 1] == 1) neigh++;
            }
            if (i == 24 && (j > 0 && j < 79)) {
                if (current_matrix[i - 1][j - 1] == 1) neigh++;
                if (current_matrix[i - 1][j] == 1) neigh++;
                if (current_matrix[i - 1][j + 1] == 1) neigh++;
                if (current_matrix[i][j - 1] == 1) neigh++;
                if (current_matrix[i][j + 1] == 1) neigh++;
                if (current_matrix[0][j - 1] == 1) neigh++;
                if (current_matrix[0][j] == 1) neigh++;
                if (current_matrix[0][j + 1] == 1) neigh++;
            }
            if (i == 24 && j == 0) {
                if (current_matrix[i - 1][79] == 1) neigh++;
                if (current_matrix[i - 1][j] == 1) neigh++;
                if (current_matrix[i - 1][j + 1] == 1) neigh++;
                if (current_matrix[i][79] == 1) neigh++;
                if (current_matrix[i][j + 1] == 1) neigh++;
                if (current_matrix[0][79] == 1) neigh++;
                if (current_matrix[0][j] == 1) neigh++;
                if (current_matrix[0][j + 1] == 1) neigh++;
            }
            if (i == 24 && j == 79) {
                if (current_matrix[i - 1][j - 1] == 1) neigh++;
                if (current_matrix[i - 1][j] == 1) neigh++;
                if (current_matrix[i - 1][0] == 1) neigh++;
                if (current_matrix[i][j - 1] == 1) neigh++;
                if (current_matrix[i][0] == 1) neigh++;
                if (current_matrix[0][j - 1] == 1) neigh++;
                if (current_matrix[0][j] == 1) neigh++;
                if (current_matrix[0][0] == 1) neigh++;
            }
            if (neigh < 2 || neigh > 3) future_matrix[i][j] = 0;
            if (current_matrix[i][j] == 1 && (neigh == 2 || neigh == 3)) future_matrix[i][j] = 1;
            if (current_matrix[i][j] == 0 && neigh == 3) future_matrix[i][j] = 1;
        }
    }
    for (int i = 0; i < YMAX; i++) {
        for (int j = 0; j < XMAX; j++) {
            current_matrix[i][j] = future_matrix[i][j];
        }
    }
    return **current_matrix;
}
void output(int (*matrix)[XMAX]) {
    printf("\n");
    system("clear");
    for (int i = 0; i < YMAX; i++) {
        for (int j = 0; j < XMAX; j++) {
            if ((j < XMAX - 1) && (i < YMAX)) {
                if (matrix[i][j] == 0)
                    printf(" ");
                else
                    printf("O");
            }
            if ((j == 79) && (i < YMAX - 1)) {
                if (matrix[i][j] == 0) {
                    printf(" \n");
                } else {
                    printf("O\n");
                }
            }
            if ((j == XMAX - 1) && (i == YMAX - 1)) {
                if (matrix[i][j] == 0)
                    printf(" ");
                else
                    printf("O");
            }
        }
    }
    sleep(1);
}
