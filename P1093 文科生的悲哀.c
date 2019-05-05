#include<stdio.h>

int n;
long times, save[4][10000];

int Cal(int subject, int num) {
    if (save[subject - 1][num] == 0) {
        if (num == 0)
            save[subject - 1][num] = 1;
        else {
            if (subject == 1)
                save[subject - 1][num] = Cal(2, num - 1);
            else if (subject == 2) {
                save[subject - 1][num] = Cal(1, num - 1);
                save[subject - 1][num] %= 7654321;
                save[subject - 1][num] += Cal(3, num - 1);
                save[subject - 1][num] %= 7654321;
            } else if (subject == 3) {
                save[subject - 1][num] = Cal(2, num - 1);
                save[subject - 1][num] %= 7654321;
                save[subject - 1][num] += Cal(4, num - 1);
                save[subject - 1][num] %= 7654321;
            } else {
                save[subject - 1][num] = Cal(3, num - 1);
                save[subject - 1][num] %= 7654321;
            }
        }
    }
    return save[subject - 1][num];
}

int main() {
    scanf("%d", &n);
    times = Cal(1, n - 1);
    printf("%ld", times);
    return 0;
}
