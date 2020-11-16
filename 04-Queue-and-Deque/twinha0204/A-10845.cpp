#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
	int N;
	cin >> N;

	queue<int> q;
	
	string input;
	getline(cin, input);
	for(int i=0;i<N;i++){
		getline(cin, input);
		if (input.length() > 5){
			q.push(stoi(input.substr(5, input.length()-5)));
		}
		else{
			if(input == "pop"){
				if(q.size() > 0){
					cout << q.front() << endl;
					q.pop();
				}
				else{
					cout << -1 << endl;
				}
			}
			else if(input == "size"){
				cout << q.size() << endl;
			}
			else if(input == "empty"){
				cout << int(q.empty()) << endl;
			}
			else if(input == "front"){
				if(q.size() > 0){
					cout << q.front() << endl;
				}
				else{
					cout << -1 << endl;
				}
			}
			else if(input == "back"){
				if(q.size() > 0){
					cout << q.back() << endl;
				}
				else{
					cout << -1 << endl;
				}
			}
		}
	}
	return 0;
}