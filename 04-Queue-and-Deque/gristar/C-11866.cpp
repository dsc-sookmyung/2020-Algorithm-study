#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	
	list<int> ls;
	vector<int> answer;
	
	for(int i=1;i<=n;i++){
		ls.push_back(i);
	}
	
	list<int>::iterator iter;
	iter=ls.begin();
	
	while(ls.size()!=0){ //list에는 empty가 없다
		for(int i=0;i<k-1;i++){
			iter++;
			if(iter==ls.end())
				iter=ls.begin();
		}

		answer.push_back(*iter);
		ls.erase(iter++); //**반환값을 받을 것이 필요하다->후위연산으로 처리**
		if(iter==ls.end())
			iter=ls.begin();
		
	}
	
	cout<<"<";
	for(int i=0;i<answer.size();i++){
		if(i==answer.size()-1){
			printf("%d>",answer[i]);
			break;
		}
		printf("%d, ",answer[i]);
	}
		
}