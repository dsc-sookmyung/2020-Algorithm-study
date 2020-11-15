#include <iostream>
#include <vector>

using namespace std;

int N, k;
vector<int> info;
int num = 0;

int main() {
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
	while (end <= N) {
		if (num < k) {
			if (info[start] != 1) {
				start++;
				if (start >= end) {
					end++;
				}
			}
			else if (info[end] == 1) {
				num++;
				end++;
			}
			else {
				end++;
			}
		}
		else if (num == k) {
			size = end - start;
			if (min > size) {
				min = size;
				if (end == N) {
					break;
				}
				else {
					if (info[start] == 1) {
						num--;
					}
					start++;
				}
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