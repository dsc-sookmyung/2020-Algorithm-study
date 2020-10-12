#include <iostream>
#include <algorithm>
using namespace std;

int num;
pair<int, int> arr[50];

int ranking()
{
    int rank = 1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
            {
                rank++;
            }
        }
        cout << rank << ' ';
        rank = 1;
    }
    return 0;
}

int main()
{
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    ranking();
    return 0;
}
