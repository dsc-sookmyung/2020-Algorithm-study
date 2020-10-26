// 좌표 압축 - 18870
#include <stdio.h>
#include <unordered_map>
#include <set>

using namespace std;

int main(void){
	int N;
	scanf("%d", &N);

	int* X = new int[N];
	for(int i=0;i<N;i++)
		scanf("%d", &X[i]);
	
	set<int> setX;
	for(int i=0;i<N;i++)
		setX.insert(X[i]);

	unordered_map<int, int> mapX;
	int count = 0;
	for(set<int>::iterator it = setX.begin(); it != setX.end(); it++)
		mapX[*it] = count++;

	for(int i=0;i<N;i++)
		printf("%d ", mapX[X[i]]);
	printf("\n");

	delete[] X;
	return 0;
}