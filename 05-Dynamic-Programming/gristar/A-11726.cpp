#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
using namespace std;

int f[1001];

int main() {
	f[1] = 1;
	f[2] = 2;

	int n;
	scanf("%d", &n);

	for (int i = 3; i <= n; i++) {
		f[i] = (f[i - 1] + f[i - 2])%10007;
	}

	printf("%d", f[n]);
}