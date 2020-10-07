// 1065 - 한수
#include <iostream>
#include <string>

using namespace std;

bool isHansoo(int n) {
	string str = to_string(n);

	int length = str.length();
	if (length < 3)
		return true;

	int dif = str[1] - str[0];
	for (int i = 2;i < length;i++) {
		int tdif = str[i] - str[i - 1];
		if (tdif != dif)
			return false;
	}

	return true;
}

int main() {
	int N;
	cin >> N;

	int count = 0;

	for (int i = 1;i <= N;i++) {
		if (isHansoo(i))
			count++;
	}

	cout << count;

	return 0;
}