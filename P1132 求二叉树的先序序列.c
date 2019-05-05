#include<stdio.h>
#include<string.h>

char xian[256], hou[256], zhong[256];

void p(int s1, int e1, int s2, int e2) {
    if (s1 <= e1 && s2 <= e2) {
        int k = 0;
        while (zhong[k] != hou[e2])
            k++;
        printf("%c", hou[e2]);
        if (k > 0)
            p(s1, k - 1, s2, k + e2 - e1 - 1);
        if (k < e1)
            p(k + 1, e1, k + e2 - e1, e2 - 1);
    }
}

int main() {
    gets(zhong);
    gets(hou);
    int hlen, zlen;
    hlen = strlen(hou);
    zlen = strlen(zhong);
    p(0, zlen - 1, 0, hlen - 1);
    return 0;
}
