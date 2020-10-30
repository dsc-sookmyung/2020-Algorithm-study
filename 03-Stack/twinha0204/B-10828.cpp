#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	int N;
	cin >> N;

	string command;
	getline(cin, command); // 엔터입력 빼기
	stack<int> s;
	for(int i=0;i<N;i++){
		getline(cin, command);
		if(command == "size"){
			cout << s.size() << endl;
		}
		else if(command == "empty"){
			cout << int(s.empty()) << endl;
		}
		else if(command == "top"){
			if(s.empty())
				cout << -1 << endl;
			else
				cout << s.top() << endl;
		}
		else if(command == "pop"){
			if(s.empty())
				cout << -1 << endl;
			else{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else{
			s.push(stoi(command.substr(5, command.length()-5)));
		}
	}
	return 0;
}