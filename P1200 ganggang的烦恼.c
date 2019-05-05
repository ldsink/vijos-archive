#include<stdio.h>

int main() {
    int n, high[1000] = {0};
    int a, b, c, d;
    scanf("%d", &n);
    for (a = n, b = 0; a > 0; b++) {
        high[b] = a % 10;
        a /= 10;
        d = b;
    }
    for (a = n - 1, c = 0; a > 1; a--)
        for (b = 0; b <= d; b++) {
            high[b] *= a;
            high[b] += c;
            c = high[b] / 10;
            high[b] %= 10;
            if (b == d && c != 0) { d++; }
        }
    for (a = 0, b = 0; a <= d; a++)
        b += high[a];
    printf("%d", b);
    for (a = 2, b = 1; a < n; a++)
        if (n % a == 0) {
            b = 0;
            break;
        }
    if (b == 0)
        printf("F");
    else
        printf("T");
    return 0;
}
