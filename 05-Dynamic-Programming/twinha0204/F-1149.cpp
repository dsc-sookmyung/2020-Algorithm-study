#include <iostream>

using namespace std;

int getMin(int a, int b, int c) {
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}

int pebble_min(int** &arr, int N) {
	int** c = new int*[3];
	for (int p = 0;p < 3;p++) {
		c[p] = new int[N];
	}

	for (int p = 0;p < 3;p++) {
		c[p][0] = arr[p][0];
	}
	for (int i = 1;i < N;i++) {
		// 나의 패턴
		for (int p = 0;p < 3;p++) {
			int min = 1000 * (i + 1);
			// 내 이웃 패턴
			for (int q = 0;q < 3;q++) {
				// 양립할 때
				if (p != q) {
					if (min > c[q][i - 1])
						min = c[q][i - 1];
				}
			}
			c[p][i] = min + arr[p][i];
		}
	}

	return getMin(c[0][N - 1], c[1][N - 1], c[2][N - 1]);
}

int main() {
	int N;
	cin >> N;

	int** house = new int*[3];
	for (int i = 0;i < 3;i++) {
		house[i] = new int[N];
	}

	for (int j = 0;j < N;j++) {
		for (int i = 0;i < 3;i++) {
			cin >> house[i][j];
		}
	}

	cout << pebble_min(house, N);

	return 0;
}