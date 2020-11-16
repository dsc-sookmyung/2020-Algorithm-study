#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
	int N;
	cin >> N;
	string input;
	getline(cin, input);
	deque<int> q;
	for(int i=0;i<N;i++){
		getline(cin, input);
		if(input.length() > 10){
			if(input.substr(0, 10) == "push_front"){
				int X = stoi(input.substr(11, input.length()-11));
				q.push_front(X);
			}
			else{
				int X = stoi(input.substr(10, input.length()-10));
				q.push_back(X);
			}
		}
		else{
			if(input == "size"){
				cout << q.size() << endl;
			}
			else if(input == "empty"){
				cout << int(q.empty()) << endl;
			}
			else if(q.empty()){
				cout << -1 << endl;
			}
			else if(input == "pop_front"){
				cout << q.front() << endl;
				q.pop_front();
			}
			else if(input == "pop_back"){
				cout << q.back() << endl;
				q.pop_back();
			}
			else if(input == "front"){
				cout << q.front() << endl;
			}
			else if(input == "back"){
				cout << q.back() << endl;
			}
		}
	}

	return 0;
}