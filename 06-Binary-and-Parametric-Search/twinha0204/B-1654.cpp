#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int K, N;
int v[10000];
long long ans = 0;

long long getCounts(int num){
	long long result = 0;
	for(int i=0;i<K;i++){
		result += (v[i] / num);
	}
	return result;
}

int main(){	
	scanf("%d", &K);
	scanf("%d", &N);

	for(int i=0;i<K;i++)
		scanf("%d", &v[i]);
	
	sort(v, v + K);
	
	long long low = 0, high = v[K-1];
	long long mid, tcount;
	while(low <= high){
		mid = ceil((low + high)/2.0);
		tcount = getCounts(mid);
		if(tcount >= N){
			ans = max(ans, mid);
			low = mid;
		}
		else{
			high = mid-1;
		}
		if(low == high){
			break;
		}
	}
	printf("%lld\n", ans);

	return 0;
}