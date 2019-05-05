#include<stdio.h>

int main() {
    int L, M, Tree[10001] = {0};
    scanf("%d %d", &L, &M);
    int a, b, c;
    for (a = 0; a < M; a++) {
        scanf("%d %d", &b, &c);
        for (; b <= c; b++)
            Tree[b] = 1;
    }
    for (a = 0, b = 0; a <= L; a++)
        if (Tree[a] == 0)
            b++;
    printf("%d", b);
    return 0;
}
