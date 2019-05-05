#include<stdio.h>
#include<math.h>

int n;

int panduan(int num) {
    int i, p;
    if (num == 2) return 1;
    if (num < 2 || num % 2 == 0)
        return 0;
    for (i = 3, p = (int) sqrt(num); i <= p && num % i; i += 2);
    return i > p;
}

void fun(int num, int d) {
    int i;
    if (d > n)
        printf("%d\n", num);
    else
        for (num *= 10, i = 0; i < 10; num++, i++)
            if (panduan(num) != 0)
                fun(num, d + 1);
}

int main() {
    scanf("%d", &n);
    fun(0, 1);
    return 0;
}
