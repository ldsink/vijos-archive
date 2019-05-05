#include<stdio.h>
#include<string.h>

char s[55];
int i, j, k, v, sh, b, q, sw, bw, qw;

int main() {
    scanf("%s", s);
    if (s[i] == '-') {
        printf("F");
        i++;
    }
    while (s[i] == '0')
        i++;
    j = i + 1;
    if (s[i] == '.') {
        v = 1;
        j = i;
    }
    while (j < strlen(s) && s[j] != '.')
        j++;
    if (s[i] == '.')
        i--;
    if (i == -1) k = 0;
    else k = j - i;
    if (j == strlen(s) + 1) printf("0");
    else {
        v = sh = b = q = sw = bw = qw = 0;
        while (k > 0) {
            switch (k) {
                case 1:
                    if (s[j - k] != '0') {
                        if ((!sh) && v)
                            printf("0");
                        printf("%c", s[j - k]);
                        v = 1;
                    }
                    break;
                case 2:
                    if (s[j - k] != '0') {
                        sh = 1;
                        if ((!b) && v)
                            printf("0");
                        printf("%cS", s[j - k]);
                        v = 1;
                    }
                    break;
                case 3:
                    if (s[j - k] != '0') {
                        b = 1;
                        if ((!q) && v)
                            printf("0");
                        printf("%cB", s[j - k]);
                        v = 1;
                    }
                    break;
                case 4:
                    if (s[j - k] != '0') {
                        q = 1;
                        printf("%cQ", s[j - k]);
                        v = 1;
                    }
                    break;
                case 5:
                    if (s[j - k] != '0') {
                        if ((!sw) && v)
                            printf("0");
                        printf("%c", s[j - k]);
                        v = 1;
                    }
                    if (qw || bw || sw || s[j - k] != '0') printf("W");
                    break;
                case 6:
                    if (s[j - k] != '0') {
                        sw = 1;
                        if ((!bw) && v)
                            printf("0");
                        printf("%cS", s[j - k]);
                        v = 1;
                    }
                    break;
                case 7:
                    if (s[j - k] != '0') {
                        bw = 1;
                        if ((!qw) && v)
                            printf("0");
                        printf("%cB", s[j - k]);
                        v = 1;
                    }
                    break;
                case 8:
                    if (s[j - k] != '0') {
                        qw = 1;
                        printf("%cQ", s[j - k]);
                        v = 1;
                    }
                    break;
                case 9:
                    printf("%cY", s[j - k]);
                    v = 1;
                    break;
            }
            k--;
        }
    }
    if (s[j] == '.' && s[j + 1] == '\0')
        return 0;
    if (j < strlen(s)) {
        if (!v)
            printf("0");
        printf("D");
        for (k = j + 1; k < strlen(s); k++)
            printf("%c", s[k]);
    }
    return 0;
}
