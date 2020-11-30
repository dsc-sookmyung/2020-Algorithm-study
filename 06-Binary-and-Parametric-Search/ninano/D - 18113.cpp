//그르다 김가놈
#include <cstdio>
#include <algorithm>

using namespace std;

int n, K, m;
int w[1010000];

int main()
{
    int i;
    scanf("%d%d%d", &n, &K, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        if (w[i] >= 2 * K)
            w[i] -= 2 * K;
        else if (w[i] >= K)
            w[i] -= K;
        else
            w[i] = 0;
    }
    int b = 1, e = 1e9, res = -1, mid;
    while (b <= e)
    {
        mid = (b + e) >> 1;
        long long s = 0;
        for (i = 1; i <= n; i++)
            s += w[i] / mid;
        if (s >= m)
        {
            res = mid;
            b = mid + 1;
        }
        else
            e = mid - 1;
    }
    printf("%d\n", res);
}
