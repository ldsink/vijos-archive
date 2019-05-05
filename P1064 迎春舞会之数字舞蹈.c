#include<stdio.h>
#include<string.h>

char b[10][7] = {"|-| ||-", "  |  | ", " -|-| -", " -|- |-", "| |- | ", "|- - |-", "|- -||-", " -|  | ", "|-|-||-",
                 "|-|- |-"};
char s[256];

int i, j, k, n, h;

int main() {
    scanf("%d", &k);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (i = 1; i <= n; i++) {
        if (i == 1)
            printf(" ");
        else
            printf("  ");
        for (j = 1; j <= k; j++)
            printf("%c", b[s[i] - 48][1]);
        printf(" ");
    }
    printf("\n");
    for (h = 1; h <= k; h++) {
        for (i = 1; i <= n; i++) {
            if (i == 1)
                printf("%c", b[s[i] - 48][0]);
            else
                printf(" %c", b[s[i] - 48][0]);
            for (j = 1; j <= k; j++)
                printf(" ");
            printf("%c", b[s[i] - 48][2]);
        }
        printf("\n");
    }
    for (i = 1; i <= n; i++) {
        if (i == 1)
            printf(" ");
        else
            printf("  ");
        for (j = 1; j <= k; j++)
            printf("%c", b[s[i] - 48][3]);
        printf(" ");
    }
    printf("\n");
    for (h = 1; h <= k; h++) {
        for (i = 1; i <= n; i++) {
            if (i == 1)
                printf("%c", b[s[i] - 48][4]);
            else
                printf(" %c", b[s[i] - 48][4]);
            for (j = 1; j <= k; j++)
                printf(" ");
            printf("%c", b[s[i] - 48][5]);
        }
        printf("\n");
    }
    for (i = 1; i <= n; i++) {
        if (i == 1)
            printf(" ");
        else
            printf("  ");
        for (j = 1; j <= k; j++)
            printf("%c", b[s[i] - 48][6]);
        printf(" ");
    }
    printf("\n");
    return 0;
}
