#include<stdio.h>

int main() {
    int N, K, F, page, cost, in[1001] = {0};
    scanf("%d %d", &N, &K);
    scanf("%d", &F);
    int a, b, c, d;
    for (; F > 0; F--) {
        scanf("%d %d", &a, &b);
        in[a] += b;
    }
    for (a = 1, b = a, page = 1, cost = K; a <= N; a++) {
        if (in[a] < cost)
            cost -= in[a] + 1;
        else {
            page++;
            cost = K - 1 - in[a];
        }
    }
    printf("%d\n", page);
    return 0;
}
