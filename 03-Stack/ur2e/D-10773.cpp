#include<iostream>
#include<stack>

using namespace std;

int main(void){
	int cnt, num;
	int sum = 0;
	stack<int> s;
	cin >> cnt;

	for(int i = 0; i < cnt; i++){
		cin >> num;
		if( num == 0)	s.pop();
		else
			s.push(num);
	}
	
	while(!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << "\n";
	return 0;
}

