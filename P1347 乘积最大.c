#include<stdio.h>

int N, K, In[50];
long Ans, Num[50][50];

void Change(int st, int en) {
    if (Num[st][en] == 0) {
        int a, b;
        for (a = en, b = 1; a >= st; a--, b *= 10)
            Num[st][en] += b * In[a];
    }
}

long Fun(int st, int time) {
    if (time == 0) {
        Change(st, N - 1);
        return Num[st][N - 1];
    } else {
        long a, b, c;
        for (a = st, c = 0; a < N - time; a++) {
            Change(st, a);
            b = Num[st][a] * Fun(a + 1, time - 1);
            if (c < b) c = b;
        }
        return c;
    }
}

int main() {
    scanf("%d %d", &N, &K);
    long a, b;
    char ch;
    scanf("%c", &ch);
    for (a = 0; a < N; a++) {
        scanf("%c", &ch);
        In[a] = ch - '0';
    }
    for (a = 0; a < N - K; a++) {
        Change(0, a);
        b = Num[0][a] * Fun(a + 1, K - 1);
        if (Ans < b) Ans = b;
    }
    printf("%ld\n", Ans);
    return 0;
}
