// 수 정렬하기 2 - 2751
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main(void){
	int N;
	scanf("%d", &N);

	vector<int> nums(N);
	for(int i=0;i<N;i++)
		scanf("%d", &nums[i]);
	
	sort(nums.begin(), nums.end());

	for(int i=0;i<N;i++)
		printf("%d\n", nums[i]);

	return 0;
}