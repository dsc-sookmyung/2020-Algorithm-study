/* 11053: ���� �� �����ϴ� �κ� ���� */
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int d[1000];
// d[x]: x��° ���� ���������� �ϴ� ���� �κ� ���� �� ���� �� ���� ����
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