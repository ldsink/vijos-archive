#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, k, m, count, temp, i;
    scanf("%d %d", &n, &k);
    for (i = 0, m = 0; i < n; i++) {
        count = 0;
        while (1) {
            scanf("%d", &temp);
            if (temp != 0)
                count++;
            else
                break;
        }
        if (count >= k)
            m++;
    }
    printf("%d\n", m);
    return 0;
}
