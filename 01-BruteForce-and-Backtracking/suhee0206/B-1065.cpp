#include<iostream>
using namespace std;


int sol(int N) {
	int ans = 0;

	if (N < 100) {
		ans = N;
	}
	else if (100 <= N && N <= 1000) {
		ans += 99;

		for (int i = 100; i <= N; i++) {
			int hundreds = i / 100;
			int tens = (i % 100) / 10;
			int ones = i % 10;

			if (hundreds - tens == tens - ones) {
				ans++;
			}
		}
	}

	return ans;
}

int main() {
	int N;
	cin >> N;

	cout << sol(N);
}