#include<stdio.h>

int main() {
    int K, a, b, c;
    scanf("%d", &K);
    for (; K > 0; K--) {
        scanf("%d", &a);
        scanf("%d", &b);
        if (b == 0)
            printf("wind\n");
        else
            printf("lolanv\n");
        for (; a > 0; a--)
            scanf("%*d");
    }
    return 0;
}
