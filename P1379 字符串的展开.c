#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int p1, p2, p3, l, count;
char ch[110];

void Change();

int main() {
    scanf("%d %d %d", &p1, &p2, &p3);
    ch[0] = getchar();
    l = -1;
    do {
        l++;
        ch[l] = getchar();
    } while (ch[l] != '\n');
    for (count = 0; count < l; count++) {
        if (ch[count + 1] != '-')
            printf("%c", ch[count]);
        else
            Change();
    }
    return (0);
}

void Change() {
    char qian, hou;
    qian = ch[count];
    hou = ch[count + 2];
    if ('0' <= qian && qian <= '9' && 'a' <= hou && hou <= 'z') {
        printf("%c-", qian);
        count++;
    } else if ('0' <= hou && hou <= '9' && 'a' <= qian && qian <= 'z') {
        printf("%c-", qian);
        count++;
    } else if (qian == '-') {
        printf("--");
        count++;
    } else if (hou - qian > 1) {
        if (p1 == 1)//p1=1�����Сд��ĸ
        {
            printf("%c", qian);
            int j;
            char z;
            if (p3 == 1)
                for (z = qian + 1; z < hou; z++)
                    for (j = 0; j < p2; j++)
                        printf("%c", z);
            else
                for (z = hou - 1; z > qian; z--)
                    for (j = 0; j < p2; j++)
                        printf("%c", z);
            count++;
        } else if (p1 == 2)//p1=2������д��ĸ
        {
            printf("%c", qian);
            int j;
            char z;
            if ('a' <= qian && qian <= 'z') {
                if (p3 == 1)
                    for (z = qian + 1; z < hou; z++)
                        for (j = 0; j < p2; j++)
                            printf("%c", z - 32);
                else
                    for (z = hou - 1; z > qian; z--)
                        for (j = 0; j < p2; j++)
                            printf("%c", z - 32);
            } else {
                if (p3 == 1)
                    for (z = qian + 1; z < hou; z++)
                        for (j = 0; j < p2; j++)
                            printf("%c", z);
                else
                    for (z = hou - 1; z > qian; z--)
                        for (j = 0; j < p2; j++)
                            printf("%c", z);
            }
            count++;
        } else//p1=3����"*"����䡣
        {
            printf("%c", qian);
            int j1, j2;
            j1 = hou - qian - 1;
            for (j2 = 0; j2 < (j1 * p2); j2++)
                printf("*");
            count++;
        }
    } else if (hou - qian == 1) {
        printf("%c", qian);
        count++;
    } else {
        printf("%c-", qian);
        count++;
    }
}
