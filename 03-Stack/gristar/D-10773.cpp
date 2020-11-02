#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<int> st;
	
	int k;
	scanf("%d",&k);
	
	for(int i=0;i<k;i++){
		int n;
		scanf("%d",&n);
		
		if(n==0){
			st.pop();
		}else{
			st.push(n);
		}
	}
	
	int sum=0;
	
	while(!st.empty()){
		sum+=st.top();
		st.pop();
	}
	
	printf("%d",sum);
}