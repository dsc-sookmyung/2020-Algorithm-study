//좌표 압축
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int N, cnt;

int main()
{
    cin >> N;
    int *arr = new int[N];
    int *copy = new int[N];
    map<int, int> map;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        copy[i] = arr[i];
    }
    sort(copy, copy + N);
    map[copy[0]] = cnt++;
    for (int i = 1; i < N; i++)
    {
        if (copy[i] != copy[i - 1])
        {
            map[copy[i]] = cnt++;
        }
    }
    for (int i = 0; i < N; i++)
        cout << map[arr[i]] << " ";

    return 0;
}