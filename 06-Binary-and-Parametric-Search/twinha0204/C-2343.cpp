#include <stdio.h>
#include <limits.h>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int v[100000];

int getCounts(int length){
	int result = 1;
	int temp = 0;
	for(int i=0;i<N;i++){
		if(temp + v[i] > length){
			result++;
			temp = v[i];
		}
		else{
			temp += v[i];
		}
	}
	return result;
}

int main(){
	scanf("%d", &N);
	scanf("%d", &M);

	int sum = 0;
	for(int i=0;i<N;i++){
		scanf("%d", &v[i]);
		sum += v[i];
	}

	int low = (*max_element(v, v+N)), high = sum;
	int mid, tcount, ans = sum;
	while(low <= high){
		mid = floor((low + high)/2.0);
		tcount = getCounts(mid);
		if(tcount > M){
			low = mid + 1;
		}
		else{
			ans = min(ans, mid);
			high = mid;
		}

		if(low == high){
			break;
		}
	}
	printf("%d\n", ans);

	return 0;
}