//AC, 사실 미완성
#include <stdio.h>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
char arr[100001];
int main()
{
    int T;
    scanf("%d", &T);
    int num, n;
    char c;

    for (int i = 0; i < T; i++)
    {
        int cnt = 0, flag = 0;
        deque<int> deq;
        scanf("%s", &arr);
        scanf("%d\n", &n);
        scanf("%c", &c);
        if (n != 0)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d%c", &num, &c);
                deq.push_back(num);
            }
        }
        else
            scanf("%c%c", &c, &c);
        for (int j = 0; arr[j] != '\0'; j++)
        {
            if (arr[j] == 'R')
                cnt++;
            else if (arr[j] == 'D')
            {
                if (deq.empty())
                {
                    flag = 1;
                    break;
                }
                else
                {
                    if (cnt % 2 == 0)
                        deq.pop_front();
                    else
                        deq.pop_back();
                }
            }
        }
        if (cnt % 2 != 0)
            reverse(deq.begin(), deq.end());
        if (flag == 0)
        {
            int value = deq.size();
            printf("[");
            for (int j = 0; j < value; j++)
            {
                printf("%d", deq.front());
                deq.pop_front();
                if (j != value - 1)
                    printf(",");
            }
            printf("]\n");
        }
        else
            printf("error\n");
    }
}