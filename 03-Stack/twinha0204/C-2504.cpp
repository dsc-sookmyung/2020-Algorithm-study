#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkString(string v){
	stack<char> s;
	bool flag = true;
	for(int i=0;i<v.length();i++){
		if(v[i] == '(' || v[i] == '['){
			s.push(v[i]);
		}
		else if(s.empty()){
			flag = false;
			break;
		}
		else if(v[i] == ')' && s.top() == '('){
			s.pop();
		}
		else if(v[i] == ']' && s.top() == '['){
			s.pop();
		}
		else{
			flag = false;
			break;
		}
	}
	if(!s.empty()){
		flag = false;
	}
	return flag;
}

int calculateString(string v){
	stack<string> s;
	for(int i=0;i<v.length();i++){
		if(v[i] == '(' || v[i] == '['){
			string str(1, v[i]);
			s.push(str);
		}
		else if(v[i] == ')'){
			if(s.top() == "("){
				s.pop();
				s.push("2");
			}
			else{
				int temp = 0;
				while(s.top() != "("){
					temp += stoi(s.top());
					s.pop();
				}
				s.pop();
				s.push(to_string(2*temp));
			}
		}
		else{ // v[i] == ']'
			if(s.top() == "["){
				s.pop();
				s.push("3");
			}
			else{
				int temp = 0;
				while(s.top() != "["){
					temp += stoi(s.top());
					s.pop();
				}
				s.pop();
				s.push(to_string(3*temp));
			}
		}
	}

	int result = 0;
	while(!s.empty()){
		result += stoi(s.top());
		s.pop();
	}
	return result;
}

int main(){
	string v;
	cin >> v;

	if(checkString(v)){
		cout << calculateString(v) << endl;
	}
	else{
		cout << 0 << endl;
	}
	
	return 0;
}