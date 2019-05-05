#include<stdio.h>

char Str[10010];
long Alen, Blen, L, A[10010], B[10010], Ans[20020];

int main() {
    long a, b;
    scanf("%s", &Str);
    Alen = strlen(Str);
    for (a = 0; a < Alen; a++)
        A[a] = Str[Alen - 1 - a] - '0';
    scanf("%s", &Str);
    Blen = strlen(Str);
    for (a = 0; a < Blen; a++)
        B[a] = Str[Blen - 1 - a] - '0';
    for (a = 0; a < Alen; a++)
        for (b = 0; b < Blen; b++)
            Ans[a + b] += A[a] * B[b];
    L = Alen + Blen - 2;
    a = 0;
    b = 0;
    while (a <= L) {
        Ans[a] += b;
        b = Ans[a] / 10;
        Ans[a] %= 10;
        if (a == L && b != 0)
            L++;
        a++;
    }
    for (; L >= 0; L--)
        printf("%d", Ans[L]);
    return 0;
}
