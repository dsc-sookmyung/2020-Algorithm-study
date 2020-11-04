#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int cnt, num;
	int stack[10000];
	int peek = -1;
	string cmd;
	scanf("%d", &cnt);
	
	for(int i = 0; i < cnt; i++){
		cin >> cmd;

		if( cmd == "push"){
			scanf("%d", &num);
			stack[++peek] = num;	
		}
		else if( cmd == "pop"){
			if( peek == -1 )	printf("-1\n");
			else 
				printf("%d\n", stack[peek--]);
		}
		else if( cmd == "size"){
			printf("%d\n", peek+1);
		}
		else if( cmd == "empty" ){
			if( peek == -1 )	printf("1\n");
			else printf("0\n");
		}
		else if( cmd == "top" ){
			if( peek == -1 )	printf("-1\n");
			else 
				printf("%d\n", stack[peek]); 
		}
	}

	return 0;
}
