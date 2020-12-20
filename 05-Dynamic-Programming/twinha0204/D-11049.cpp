#include <iostream>
#include <climits>

using namespace std;

int matrixChain(int* &p, int N) {
	int** m = new int*[N];
	for (int i = 0;i < N;i++) {
		m[i] = new int[N];
		m[i][i] = 0;
	}

	for (int range = 1;range < N;range++) {

		for (int i = 0;i < N - range;i++) {

			int j = i + range;

			int min = INT_MAX;
			for (int k = i;k < j;k++) {
				int tmp = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (min > tmp)
					min = tmp;
			}

			m[i][j] = min;
		}
	}

	return m[0][N - 1];
}

int main() {
	int N;
	cin >> N;

	int* size = new int[N + 1];
	cin >> size[0] >> size[1];
	for (int i = 2;i < N + 1;i++) {
		cin >> size[i];
		cin >> size[i];
	}

	cout << matrixChain(size, N) << endl;

	return 0;
}