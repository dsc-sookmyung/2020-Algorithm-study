//귀여운 라이언
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000000];
int main()
{
    int k, n, ans = 999999999, cnt = 0, l, r;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    l = r = 0;
    while (l <= r)
    {
        if (r < n && cnt < k)
        {
            if (arr[r] == 1)
                cnt++;
            r++;
        }
        else
        {
            if (arr[l] == 1)
                cnt--;
            l++;
        }
        if (cnt == k)
            ans = min(ans, r - l);
    }
    if (ans == 999999999)
        printf("-1");
    else
        printf("%d", ans);

    return 0;
}