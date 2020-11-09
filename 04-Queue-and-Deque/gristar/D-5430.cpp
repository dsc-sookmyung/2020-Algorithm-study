#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	int T;
	cin>>T;
	
	for(int t=0;t<T;t++){
		string fun;
		cin>>fun;
		
		int n;
		cin>>n;
		
		string arr;
		cin>>arr;
		
		deque<int> dq;
		
		string tmp; //두 자리 숫자 입력받기위해
		
		for(int i=0;i<arr.length();i++){
			if(arr[i]=='[')
				continue;
			else if(arr[i]>='0'&&arr[i]<='9')
				tmp+=arr[i];
			else if(arr[i]==','||arr[i]==']'){
				if(!tmp.empty()){
					dq.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}
		

		bool rev=true;
		bool flag=true;
		
		for(int i=0;i<fun.length();i++){
			if(fun[i]=='R'){
				rev=!rev;
			}
			else{
				if(dq.empty()){
					printf("error\n");
					flag=false;
					break;
				}
				else{
					if(rev){
						dq.pop_front();
					}else{
						dq.pop_back();
					}
				}
			}
		}
		
		if(flag){
			if(rev){
				cout<<"[";
				while(!dq.empty()){
					cout<<dq.front();
					dq.pop_front();
					if(!dq.empty())
						cout<<",";
				}
				cout<<"]\n";
			}else{
				cout<<"[";
				while(!dq.empty()){
					cout<<dq.back();
					dq.pop_back();
					if(!dq.empty())
						cout<<",";
				}
				cout<<"]\n";
			}
			
		}
	}
}