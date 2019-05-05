#include<stdio.h>

int main() {
    char words[2000][76];
    int max[2000], n, i, j, k, maxv;
    scanf("%d", &n);
    for (i = 0, maxv = 0; i < n; i++) {
        scanf("%s", words[i]);
        max[i] = 1;
        for (j = i - 1; j >= max[i] - 1; j--)
            if (max[j] >= max[i]) {
                for (k = 0; words[j][k]; k++)
                    if (words[j][k] != words[i][k])
                        break;
                if (!words[j][k])
                    max[i] = max[j] + 1;
            }
        if (maxv < max[i])
            maxv = max[i];
    }
    printf("%d", maxv);
    return 0;
}
