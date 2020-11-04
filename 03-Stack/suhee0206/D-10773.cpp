#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> v;
int val;
int sum = 0;

int main() {
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> val;
		if (val == 0) {
			v.pop_back();
			continue;
		}
		else {
			v.push_back(val);
		}
	}

	if (v.empty()) {
		puts("0");
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}
		printf("%d", sum);
	}
}