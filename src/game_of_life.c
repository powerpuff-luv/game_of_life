#include <ncurses.h>
#include <stdio.h>
#define width 80
#define height 25

int input(int a[][width]);
void output(int a[][width]);
void generation(int a[][width], int *game);
int neighbors(int a[][width], int k, int l);
int inputChar(int *delay, int *game);

int main() {
    int matrix[height][width];
    if (input(matrix) && freopen("/dev/tty", "r", stdin) != NULL) {
        initscr();
        curs_set(0);
        noecho();
        output(matrix);
        int delay = 1000;
        int game = 1;
        while (game) {
            timeout(delay);
            if (!inputChar(&delay, &game)) {
                generation(matrix, &game);
                output(matrix);
            }
        }
        endwin();
    } else {
        printf("n/a");
    }
    return 0;
}

int inputChar(int *delay, int *game) {
    int mis = 1;
    int c;
    if ((c = getch()) >= 0) {
        if ((char)c == 'a' && *delay > 100) {
            *delay -= 100;
        } else if ((char)c == 'z') {
            *delay += 100;
        } else if ((char)c == 'q') {
            *game = 0;
        }
    } else {
        mis = 0;
    }
    return mis;
}

int input(int a[][width]) {
    int mis = 1;
    for (int i = 0; i < height && mis; i++) {
        for (int j = 0; j < width && mis; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                mis = 0;
            }
        }
    }
    return mis;
}

void output(int a[][width]) {
    clear();
    for (int i = -1; i <= height; i++) {
        for (int j = -1; j <= width; j++) {
            if (i == -1 || i == height) {
                printw("-");
            } else if (j == -1 || j == width) {
                printw("|");
            } else if (a[i][j]) {
                printw("O");
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
    refresh();
}

void generation(int a[][width], int *game) {
    int matrix[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int n = neighbors(a, i, j);
            if (a[i][j]) {
                if (n > 3 || n < 2) {
                    matrix[i][j] = 0;
                }
            } else {
                if (n == 3) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
    int mis = 0;
    for (int i = 0; i < height && !mis; i++) {
        for (int j = 0; j < width && !mis; j++) {
            if (a[i][j] != matrix[i][j]) {
                mis = 1;
            }
        }
    }
    if (mis) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                a[i][j] = matrix[i][j];
            }
        }
    } else {
        *game = 0;
    }
}

int neighbors(int a[][width], int k, int l) {
    int count = 0;
    for (int i = k - 1; i < k + 2; i++) {
        for (int j = l - 1; j < l + 2; j++) {
            if (i != k || j != l) {
                count += a[(height + i) % height][(width + j) % width];
            }
        }
    }
    return count;
}