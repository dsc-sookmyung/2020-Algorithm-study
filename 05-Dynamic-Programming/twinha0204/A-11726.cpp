#include <iostream>

using namespace std;

int main(){
	int n;
	int m[1001] = { 0, 1, 2, };

	cin >> n;
	for(int i = 3; i <= n; i++){
		m[i] = (m[i-1] + m[i-2]) % 10007;
	}
	cout << m[n] << endl;

	return 0;
}