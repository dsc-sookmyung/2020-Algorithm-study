#include<stdio.h>
#include<algorithm>

int main() {
    int cnt;
    scanf( "%d", &cnt);
    int *num = new int[cnt];

    for (int i=0 ; i < cnt; i++){
        scanf("%d", &num[i]); 
    }
	
	std::sort(num, num+cnt);

    for (int i = 0; i < cnt; i++){
        printf("%d\n", num[i]);
    }
    delete[] num;
    return 0;
}

