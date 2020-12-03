/* 랜선 자르기 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;

long long int binarySearch(vector<int>& v) {
	long long int start = 1;
	long long int end = 2147483648;

	long long int result = 0;
	while (start <= end) {
		long long int total = 0;
		long long int mid = (start + end) / 2;
		for (int i = 0; i < K; i++) {
			if (v[i] >= mid) {
				total += v[i] / mid;
			}
		}
		if (total < N) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}

	return result;
}

int main() {
	scanf("%d %d", &K, &N);

	vector<int> v;
	int len;
	for (int i = 0; i < K; i++) {
		scanf("%d", &len);
		v.push_back(len);
	}

	sort(v.begin(), v.end());

	printf("%lld", binarySearch(v));
}