#include<stdio.h>

int main() {
    int N, R, Ans[30], a, b;
    while (scanf("%ld %ld", &N, &R) != -1) {
        printf("%ld=", N);
        a = 0;
        while (N != 0) {
            a++;
            Ans[a] = N % R;
            N = N / R;
            if (Ans[a] < 0) {
                Ans[a] = Ans[a] - R;
                N++;
            }
        }
        for (b = a; b > 0; b--) {
            if (Ans[b] < 10)
                printf("%d", Ans[b]);
            else
                printf("%c", Ans[b] + 'A' - 10);
        }
        printf("(base %d)\n", R);
    }
    return 0;
}
