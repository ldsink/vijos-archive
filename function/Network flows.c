/*
Author ZHOU Cheng
Date 2010-3-14
Network flows
*/

#include<stdio.h>

int N, M, Ans, Add, Traffic[222][222], Back[222], Now[222];
char Pan, Mark[222];

void Find(int point) {
    if (point != M) {
        Mark[point] = 1;
        int a, b;
        for (a = 2; a <= M; a++)
            if (Traffic[point][a] > 0 && Mark[a] == 0) {
                if (Traffic[point][a] >= Now[point] && Now[point] > Now[a]) {
                    Now[a] = Now[point];
                    Back[a] = point;
                    Find(a);
                } else if (Traffic[point][a] < Now[point]) {
                    b = Traffic[point][a];
                    if (b > Now[a]) {
                        Now[a] = b;
                        Back[a] = point;
                        Find(a);
                    }
                }
            }
        Mark[point] = 0;
    }
}

void Set(int point) {
    if (point != 1) {
        int a, b;
        a = Back[point];
        b = point;
        Traffic[a][b] -= Add;
        Traffic[b][a] += Add;
        Set(a);
    }
}

int main() {
    freopen("Network flows.in", "r", stdin);
    freopen("Network flows.out", "w", stdout);
    scanf("%d %d", &N, &M);
    int a, b, c, d;
    for (a = 0; a < N; a++) {
        scanf("%d %d", &b, &c);
        scanf("%d", &d);
        Traffic[b][c] += d;
    }
    Pan = 1;
    Ans = 0;
    while (Pan) {
        memset(Back, 0, sizeof(Back));
        memset(Now, 0, sizeof(Now));
        for (a = 2, Pan = 0; a <= M; a++)
            if (Traffic[1][a] > 0 && Traffic[1][a] > Now[a]) {
                Back[a] = 1;
                Now[a] = Traffic[1][a];
                Find(a);
            }
        if (Now[M] != 0) {
            Pan = 1;
            Add = Now[M];
            Set(M);
            Ans += Add;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
