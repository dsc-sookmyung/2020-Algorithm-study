/* 11053: 가장 긴 증가하는 부분 수열 */
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int d[1000];
// d[x]: x번째 수를 마지막으로 하는 증가 부분 수열 중 가장 긴 것의 길이
vector <int> A;

int main() {
	int N;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		A.push_back(num);
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		int maxSub = 0;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				if (maxSub < d[j])
					maxSub = d[j];
			}
		}
		d[i] = maxSub + 1;
		if (max < d[i]) {
			max = d[i];
		}
	}

	printf("%d", max);
}