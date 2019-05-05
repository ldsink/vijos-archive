#include<stdio.h>

int N, Switch, Site[3];

int main() {
    scanf("%d", &N);
    scanf("%d %d %d", &Site[0], &Site[1], &Site[2]);
    int a, b, c;
    if (Site[0] > Site[1]) {
        a = Site[0];
        Site[0] = Site[1];
        Site[1] = a;
    }
    if (Site[0] > Site[2]) {
        a = Site[0];
        Site[0] = Site[2];
        Site[2] = a;
    }
    if (Site[1] > Site[2]) {
        a = Site[2];
        Site[2] = Site[1];
        Site[1] = a;
    }
    //�жϺ��������Ƿ����ⲿ��
    if (Site[0] + 1 == Site[1] && Site[1] + 1 == Site[2])
        Switch = 1;
    else if (Site[0] == 0 && Site[1] == N - 2 && Site[2] == N - 1)
        Switch = 1;
    else if (Site[0] == 0 && Site[1] == 1 && Site[2] == N - 1)
        Switch = 1;
    //�������������ڲ��Ľ����
    if (Switch == 0) {
        N -= 3;
        if (N % 2 == 0) Switch = 0;
        else Switch = 1;
    }
    if (Switch == 1) printf("JMcat Win\n");
    else printf("PZ Win\n");
    return 0;
}
