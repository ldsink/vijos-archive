#include <stdio.h>

int N;
char Num[1001];

int main() {
    scanf("%d", &N);
    int var;
    for (; N > 0; N--) {
        scanf("%d", &var);
        Num[var] = 1;
    }
    for (var = 1; var < 1001; var++)
        if (Num[var]) N++;
    printf("%d\n", N);
    for (var = 1; var < 1001; var++)
        if (Num[var])
            printf("%d ", var);
    return 0;
}