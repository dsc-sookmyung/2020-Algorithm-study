#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll getIce[1000002];
ll ice_gram[1000002];

int main(){
	ll n,k,x,g;
	cin>>n>>k;

	for(int i=0;i<n;i++){
		cin>>g>>x;
		
		ice_gram[x]=g;
	}
	
	getIce[0]=ice_gram[0];
	
	ll answer=0;
	
	for(int i=1;i<=1000000;i++){
		getIce[i]=getIce[i-1]+ice_gram[i]; //얼음이 없는 곳은 0으로 자동 초기화가 되어 있음
	}
	
	if(k<=1000000){
		for(int i=0;i<=1000000;i++){
			if(i+k<=1000000&&i-k>=1){
				answer=max(answer,getIce[i+k]-getIce[i-k-1]);
			}
		}
	}else{
		answer=getIce[1000000];
	}
	
	cout<<answer;
}