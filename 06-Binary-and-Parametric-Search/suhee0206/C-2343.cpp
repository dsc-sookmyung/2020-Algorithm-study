/* ±‚≈∏ ∑πΩº */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	vector<int> v;
	int num;
	int sum = 0;
	int maxVal = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		sum += num;
		v.push_back(num);
		maxVal = max(maxVal, num);
	}

	int low = maxVal;
	int high = sum;

	while (low <= high) {
		int cnt = 0;
		int total = 0;
		int mid = (low + high) / 2;

		for (int i = 0; i < N; i++) {
			if (total + v[i] > mid) {
				cnt++;
				total = 0;
			}
			total += v[i];
		}
		cnt++;

		if (cnt <= M) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	printf("%d", low);
}