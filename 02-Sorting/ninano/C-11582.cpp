//치킨 TOP N
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    k = N / k;

    for (int i = 0; i < N; i = i + k)
        sort(arr + i, arr + i + k);

    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}