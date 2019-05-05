#include<stdio.h>

int N, Top, Ans[10000];

int main() {
    scanf("%d", &N);
    int a, b, c;
    for (Top = 0, c = 0, Ans[0] = 2; N > 1; N--) {
        a = 0;
        while (a <= Top) {
            Ans[a] *= 2;
            Ans[a] += c;
            c = Ans[a] / 10000;
            Ans[a] %= 10000;
            if (a == Top && c != 0)
                Top++;
            a++;
        }
        Ans[0] += 2;
        a = 1;
        c = Ans[0] / 10000;
        Ans[a] %= 10000;
        while (c != 0) {
            Ans[a] += c;
            c = Ans[a] / 10000;
            Ans[a] %= 10000;
            if (a == Top && c != 0)
                Top++;
            a++;
        }
    }
    if (Top == 0)
        printf("%d", Ans[0]);
    else {
        printf("%d", Ans[Top]);
        Top--;
        for (; Top >= 0; Top--)
            if (Ans[Top] > 999)
                printf("%d", Ans[Top]);
            else if (Ans[Top] > 99)
                printf("0%d", Ans[Top]);
            else if (Ans[Top] > 9)
                printf("00%d", Ans[Top]);
            else
                printf("000%d", Ans[Top]);
    }
    printf("\n");
    return 0;
}
