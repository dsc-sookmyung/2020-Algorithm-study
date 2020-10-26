#include <iostream>
#include <algorithm>
using namespace std;

int store[1048577];
int tmp[1048577];
int k,n;

void merge(int p,int q,int r){
	
	if(r-p>n/k)
		return;
	
	int i=p;
	int j=q+1;
	int t=0;
	
	while(i<=q&&j<=r){
		if(store[i]<=store[j])
			tmp[t++]=store[i++];
		else
			tmp[t++]=store[j++];
	}
	
	while(i<=q)
		tmp[t++]=store[i++];
	while(j<=r)
		tmp[t++]=store[j++];
	
	i=p;
	t=0;
	
	while(i<=r)
		store[i++]=tmp[t++];
}

void mergeSort(int p,int r){
	if(p<r){
		int q=(p+r)/2;
		mergeSort(p,q);
		mergeSort(q+1,r);
		merge(p,q,r);
	}
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&store[i]);
	}
	scanf("%d",&k);
	
	mergeSort(0,n-1);
	
	for(int i=0;i<n;i++)
		printf("%d ",store[i]);
}