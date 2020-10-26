#include <iostream>
using namespace std;

int values[1000001];
int tmp[1000001];

void merge(int p,int q,int r){
	int i=p;
	int j=q+1;
	int t=0;
	
	while(i<=q&&j<=r){
		if(values[i]<=values[j])
			tmp[t++]=values[i++];
		else
			tmp[t++]=values[j++];
	}
	
	while(i<=q)
		tmp[t++]=values[i++];
	while(j<=r)
		tmp[t++]=values[j++];
	
	i=p;
	t=0;
	
	while(i<=r)
		values[i++]=tmp[t++];
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
	int n;

	scanf("%d",&n);
	
	
	for(int i=0;i<n;i++){
		scanf("%d",&values[i]);
	}
	
	mergeSort(0,n-1);
	
	for(int i=0;i<n;i++){
		printf("%d\n",values[i]);
	}
}