/* 11726: 2xn ≈∏¿œ∏µ */
#include <iostream>
#include <stdio.h>
using namespace std;

int d[1000];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (d[x] != 0) return d[x];
	return d[x] = (dp(x - 2) + dp(x - 1)) % 10007;
}

int main() {
	int n;
	cin >> n;

	printf("%d", dp(n));
}