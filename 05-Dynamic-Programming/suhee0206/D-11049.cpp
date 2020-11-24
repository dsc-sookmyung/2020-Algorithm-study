/* 11049: Çà·Ä °ö¼À ¼ø¼­ */
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 501

int d[MAX][MAX];
int m[MAX][2];

int main() {
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &m[i][0], &m[i][1]);
	}

	for (int l = 2; l <= N; l++) {
		for (int i = 0; i <= N-l; i++) {
			int j = i + l;
			d[i][j] = 2147483647;
			for (int k = i+1; k < j; k++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j] + (m[i][0]*m[k][0]*m[j-1][1]));
			}
		}
	}

	printf("%d", d[0][N]);
}