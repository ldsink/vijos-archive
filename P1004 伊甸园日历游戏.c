#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, i, year, month, day;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &year, &month, &day);
        if (month == 9 && day == 30)
            printf("YES\n");
        else if (month == 11 && day == 30)
            printf("YES\n");
        else if ((month + day) % 2 == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
