#include <iostream>
#include <stack>

using namespace std;

int main(){
	int K, num;
	cin >> K;

	stack<int> s;
	for(int i=0;i<K;i++){
		cin >> num;
		if(num == 0){
			s.pop();
		}
		else{
			s.push(num);
		}
	}

	int result = 0;
	while(!s.empty()){
		result += s.top();
		s.pop();
	}
	cout << result << endl;
	
	return 0;
}