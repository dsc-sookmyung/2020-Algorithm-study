#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int N, K, M;
int L[1000001];
int ans = -1;

long long getCounts(int length){
	long long result = 0;
	for(int i=0;i<N;i++){
		result += (L[i] / length);
	}
	return result;
}

int main(){
	scanf("%d", &N);
	scanf("%d", &K);
	scanf("%d", &M);
	for(int i=0;i<N;i++)
		scanf("%d", &L[i]);

	for(int i=0;i<N;i++){
		if(L[i] >= 2*K)
			L[i] -= 2*K;
		else if(L[i] > K)
			L[i] -= K;
		else
			L[i] = 0;
	}

	int low = 1, high = *max_element(L, L+N), mid;
	long long tcount;
	while(low <= high){
		mid = (low + high) >> 1;
		tcount = getCounts(mid);
		if(tcount >= M){
			ans = max(ans, mid);
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	printf("%d\n", ans);

	return 0;
}