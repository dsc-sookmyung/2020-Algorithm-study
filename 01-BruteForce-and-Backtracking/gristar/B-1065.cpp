#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cnt=0;

void solution(int n){
	bool flag=true;
	string str=to_string(n);
	
	for(int i=1;i<str.length()-1;i++){
		if(str[i]-str[i-1]!=str[i+1]-str[i]){
			flag=false;
			break;
		}
	}
	
	if(flag)
		cnt++;
}

int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		solution(i);
	}
	
	cout<<cnt;
}