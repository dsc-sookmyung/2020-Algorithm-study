#include <iostream>
#include <algorithm>
using namespace std;

int height[9];

int getSum(){
	int sum=0;
	
	for(int i=0;i<9;i++)
		sum+=height[i];
	
	return sum;
}

void solution(){
	int sum=getSum();
	
	for(int i=0;i<=7;i++){
		for(int j=i+1;j<=8;j++){
			if(sum-(height[i]+height[j])==100){
				height[i]=-1;
				height[j]=-1;
				return;
			}
		}
	}
}

int main(){
	for(int i=0;i<9;i++)
		cin>>height[i];
	
	sort(height,height+9);
	
	solution();
	
	for(int i=0;i<9;i++){
		if(height[i]!=-1)
			cout<<height[i]<<endl;
	}
}