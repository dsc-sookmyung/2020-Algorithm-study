#include <iostream>
#include <vector>

using namespace std;

int N, k;
vector<int> info;
int num = 0;

int main() {
    cin.tie(0); 
    cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> k;
	int doll;
	for (int i = 0; i < N; i++) {
		cin >> doll;
		info.push_back(doll);
	}

	int size = 0;
    int min = 10000001;

	int start = 0, end = 0;
	while (start<=end && end <= N) {
		if (num < k) {
			if (info[end] == 1) {
                num++;
			}
			end++;
		}
		else if (num == k) {
			size = end - start;
			if (min > size) {
				min = size;
				if (end == N) {
					break;
				}
            }
			if (info[start] == 1) {
				num--;
                start++;
			}
            else {
                start++;
            }
		}
	}

	if (size == 0) {
		cout << -1;
	}
	else {
		cout << min;
	}
}
