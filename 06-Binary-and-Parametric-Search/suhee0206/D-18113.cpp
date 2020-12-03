/* ±×¸£´Ù ±è°¡³ð */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N, K, M;
	int P = -1;
	scanf("%d %d %d", &N, &K, &M);

	vector<int> v;
	int l;
	int maxLen = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &l);
		v.push_back(l);
		maxLen = max(maxLen, v[i]);
	}
	
	sort(v.begin(), v.end());

	int start = 1;
	int end = maxLen - K;

	while (start <= end) {
		int cnt = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			if (v[i] >= 2 * K) {
				cnt += (v[i] - 2 * K) / mid;
			}
			else if (v[i] < 2* K && v[i] > K) {
				cnt += (v[i] - K) / mid;
			}
		}
		if (cnt < M) {
			end = mid - 1;
		}
		else {
			P = max(P, mid);
			start = mid + 1;
		}
	}

	printf("%d", P);
}