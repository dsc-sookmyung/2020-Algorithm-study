#include <iostream>
#include <string>

using namespace std;

int main(){
	string v;
	cin >> v;

	int stack = 0;
	int result = 0;
	for(int i=0;i<v.length();i++){
		if(v[i] == '('){
			stack++;
		}
		else{
			if(v[i-1] == '('){
				stack--;
				result += stack;
			}
			else{
				stack--;
				result += 1;
			}
		}
	}
	cout << result << endl;

	return 0;
}