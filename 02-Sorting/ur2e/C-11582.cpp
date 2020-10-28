#include<stdio.h>

int num, curr;
int a[1048577];
int b[1048577];
void merge(int s, int m, int e){
	if ( e-s > num/curr) return;
	int i = s;
	int j = m + 1;
	int k = 0;

	while( i<= m && j <= e){
		if( a[i] <= a[j])	b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	while ( i <= m) b[k++] = a[i++];
	while ( j <= e) b[k++] = a[j++];
	for (int i = s; i <= e; i++) a[i] = b[i-s];
}

void mergeSort(int s, int e){
	if(s < e){
        int m = (s+e)/2;
        mergeSort(s, m);
        mergeSort(m+1, e);
		merge(s, m, e);
    }
}

int main(){
	scanf("%d", &num);
	for(int i=0; i < num; i++)	scanf("%d", &a[i]);
	scanf("%d", &curr);
	mergeSort(0, num-1);
	for (int i = 0; i < num; i++){
		printf("%d ", a[i]);
	}

	return 0;
}
