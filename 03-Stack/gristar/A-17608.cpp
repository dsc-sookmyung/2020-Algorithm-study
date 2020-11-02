#include <iostream>
#include <stack>
using namespace std;


int main(){
	int n;
	scanf("%d",&n);
	
	stack<int> s;
	
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		s.push(k);
	}
	
	int j=-1;
	int cnt=0;
	
	while(!s.empty()){
		int i=s.top();
		s.pop();
		
		if(i>j){
			cnt++;
			j=i;
		}
	}
	
	printf("%d",cnt);
}