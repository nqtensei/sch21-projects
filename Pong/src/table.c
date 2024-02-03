#include <stdio.h>
#include <stdlib.h>

// метод отрисовки поля и ракеток

void printTable(int LeftR1, int RightR1, int BallX, int BallY) {
  for (int h = 0; h < 27; h++) {
    for (int w = 0; w < 82; w++) {
      if (h == 0 || h == 26 || w == 0 || w == 81) {
        printf("*");
      } else if (((h == LeftR1 || h == LeftR1 + 1 || h == LeftR1 + 2) &&
                  w == 2) ||
                 ((h == RightR1 || h == RightR1 + 1 || h == RightR1 + 2) &&
                  w == 79)) {
        printf("|");
      } else if (w == BallX && h == BallY) {
        printf("o");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// перемещение ракетки слева
int p1Turn(char key, int LeftR1) {
  if (key == 'a' && LeftR1 > 1) {
    LeftR1--;
  } else if (key == 'z' && LeftR1 < 23) {
    LeftR1++;
  }
  return LeftR1;
}
// перемещение ракетки справа
int p2Turn(char key, int RightR1) {
  if (key == 'k') {
    if (RightR1 > 1) {
      RightR1--;
    }
  } else if (key == 'm') {
    if (RightR1 < 23) {
      RightR1++;
    }
  }
  return RightR1;
}

int main() {
    int pOneScore = 0;
    int pTwoScore = 0;
    int LeftR1 = 12;
    int RightR1 = 12;
    int BallX = 3;
    int BallY = 13;
    int pBallX = BallX - 1;
    int pBallY = BallY - 1;
    char key;
    while (pOneScore <= 21 || pTwoScore <= 21) {
        if (pOneScore == 21) {
            printf("Player 1 win! Congratulations!");
            break;
        } else if (pTwoScore == 21) {
            printf("Player 2 win! Congratulations!");
            break;
        }
        key = getchar();
        if (key == 'a' || key == 'z') {
          LeftR1 = p1Turn(key, LeftR1);
          if ((pBallY == BallY - 1) && BallY < 25) {
            if (pBallX == BallX - 1) {
              pBallX = BallX;
              pBallY = BallY;
              BallX++;
              BallY++;
            }
          } else if (BallY == 25) {
            if (pBallX == BallX - 1) {
              pBallX = BallX;
              pBallY = BallY;
              BallX++;
              BallY--;
            }
          } else if ((pBallY == BallY + 1) && BallY < 25) {
            if (pBallX == BallX - 1) {
              pBallX = BallX;
              pBallY = BallY;
              BallX++;
              BallY--;
            }
          }
          // system("clear");
          printTable(LeftR1, RightR1, BallX, BallY);
          printf("\n%d - %d", BallX, pBallX);
        }
        if (key == 'k' || key == 'm') {
          RightR1 = p2Turn(key, RightR1);
          system("clear");
          printTable(LeftR1, RightR1, BallX, BallY);
        }
    }
}
