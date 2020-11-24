/* 2748: 피보나치 수 2 */
#include <iostream>
#include <stdio.h>
using namespace std;

long long d[90];

long long dp(int x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (d[x] != 0) return d[x];
	return d[x] = dp(x - 2) + dp(x - 1);
}

int main() {
	int n;
	cin >> n;

	printf("%lld", dp(n));
}