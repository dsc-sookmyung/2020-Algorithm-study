//기타 레슨
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    int arr[100000] = {0};
    int left = 0, right = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        left = max(left, arr[i]);
    }
    right = 1000000000 / m;

    while (left + 1 < right)
    {
        int mid = (right + left) / 2;
        int sum = 0, cnt = 0;

        for (int i = 0; i < n; i++)
        {

            if (sum + arr[i] >= mid)
            {
                cnt++;
                sum = 0;
            }
            sum += arr[i];
        }

        if (sum != 0)
            cnt++;

        if (cnt <= m)
            right = mid;
        else
            left = mid;
    }

    cout << left;
}