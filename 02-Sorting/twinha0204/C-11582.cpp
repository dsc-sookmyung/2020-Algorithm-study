// 치킨 TOP N - 11582
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
	int N;
	scanf("%d", &N);

	int* flavors = new int[N];
	for(int i=0;i<N;i++)
		scanf("%d", &flavors[i]);
	
	int K;
	scanf("%d", &K);

	int step = N / K;
	for(int i=0;i<N;i+=step)
		sort(flavors+i, flavors+i+step);

	for(int i=0;i<N;i++)
		printf("%d ", flavors[i]);
	printf("\n");

	delete[] flavors;
	return 0;
}