/* 숫자 카드 2 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int count(vector<int> &v, int num) {
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), num);
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), num);
	return rightIndex - leftIndex;
}

int main() {
	int N, M;
	scanf("%d", &N);

	vector<int> vN;
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		vN.push_back(num);
	}

	sort(vN.begin(), vN.end());

	scanf("%d", &M);
	vector<int> vM;
	int ans;
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		ans = count(vN, num);
		vM.push_back(ans);
	}

	for (int i = 0; i < M; i++) {
		printf("%d ", vM[i]);
	}
}