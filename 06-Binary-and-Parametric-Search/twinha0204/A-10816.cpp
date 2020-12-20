#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int N, M, temp;
	
	scanf("%d", &N);
	vector<int> v(N);
	for(int i=0;i<N;i++)
		scanf("%d", &v[i]);
	scanf("%d", &M);

	sort(v.begin(), v.end());
	for(int i=0;i<M;i++){
		scanf("%d", &temp);
		printf("%d ", upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp));
	}
	printf("\n");

	return 0;
}