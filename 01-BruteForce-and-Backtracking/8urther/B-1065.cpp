#include <iostream>
using namespace std;

bool CheckHansoo(int n) {
	int digit1, digit2, digit3;

	digit1 = n / 100;
	digit2 = (n / 10) % 10;
	digit3 = n % 10;

	int minusResult1, minusResult2;
	minusResult1 = digit1 - digit2;
	minusResult2 = digit2 - digit3;

	if (n < 100 || minusResult1 == minusResult2) return true;
	else return false;
	}

int main() {
	int num;
	cin >> num;

	int ans = 0;
	for (int i = 1; i <= num; i++) {
		if (CheckHansoo(i) == true)  ans += 1;
	}
	cout << ans << endl;

	return 0;
}