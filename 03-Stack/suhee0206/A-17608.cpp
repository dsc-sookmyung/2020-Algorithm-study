#include <iostream>
#include <vector>

using namespace std;

int N, h;

int main() {
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> h;
		v.push_back(h);
	}

	int min = 0;
	int cnt = 0;

	for (int i = N-1; i >= 0; i--) {
		if (min < v[i]) {
			min = v[i];
			cnt++;
		}
	}
	cout << cnt;
}