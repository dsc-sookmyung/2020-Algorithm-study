// 7568 - 덩치
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> ranks(N, 1);
    vector<pair<int, int>> sizes(N);
    for (int i = 0; i < N; i++) {
        cin >> sizes[i].first >> sizes[i].second;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (sizes[i].first > sizes[j].first && sizes[i].second > sizes[j].second) {
                ranks[j]++;
            }
            else if (sizes[i].first < sizes[j].first && sizes[i].second < sizes[j].second) {
                ranks[i]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ranks[i] << ' ';
    }
    cout << endl;

    return 0;
}