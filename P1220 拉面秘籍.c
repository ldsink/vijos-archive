#include<stdio.h>

int m, ans;

int fun(int a[]) {
    m--;
    int i, b[m];
    if (m == 0) {
        printf("%d", ans);
        return 0;
    }
    for (i = 0; i < m; i++)
        b[i] = a[i + 1] - a[i];
    ans += b[i - 1];
    fun(b);
}

int main() {
    int num[1000], i, j;
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%d", &num[i]);
    ans = num[m - 1];
    fun(num);
    return 0;
}
