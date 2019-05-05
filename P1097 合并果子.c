#include<stdio.h>

int N, As, Ae, Bs, Be;
long Ans, A[20000], B[20000];

void KP(int st, int en) {
    int a, b;
    long c;
    a = st, b = en, c = A[a];
    while (a < b) {
        while (a < b) {
            if (A[b] < c) {
                A[a] = A[b];
                break;
            }
            b--;
        }
        while (a < b) {
            if (A[a] > c) {
                A[b] = A[a];
                break;
            }
            a++;
        }
    }
    A[a] = c;
    if (st < a - 1) KP(st, a - 1);
    if (a + 1 < en) KP(a + 1, en);
}

long Get() {
    long a, b;
    a = 100000000;
    b = 100000000;
    if (As < Ae) a = A[As];
    if (Bs < Be) b = B[Bs];
    if (a < b) {
        As++;
        return a;
    } else {
        Bs++;
        return b;
    }
}

int main() {
    scanf("%d", &N);
    int a, b;
    for (a = 0; a < N; a++)
        scanf("%ld", &A[a]);
    KP(0, N - 1);
    Ae = N;
    for (a = 1; a < N; a++) {
        B[Be] = Get() + Get();
        Ans += B[Be];
        Be++;
    }
    printf("%ld\n", Ans);
    return 0;
}
