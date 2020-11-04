#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int cnt, num, input;
	int max = 0, count = 0;
	
	cin >> cnt;

	stack<int> s;

	for(int i = 0; i < cnt; i++) {
		cin >> input;
		s.push(input);
	}

	while(!s.empty()) {
		num = s.top();
		if( max < num ){
			max = num;
			count++;
		}
		s.pop();
	}

	cout << count << "\n";
	
	return 0;
}

