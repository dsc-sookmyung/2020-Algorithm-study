// 2039 - 일곱 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>

#define NUM 9

using namespace std;

int main() {
	vector<int> dwarf;
	int sum = 0;

	for (int i = 0;i < NUM;i++) {
		int tmp;
		cin >> tmp;
		dwarf.push_back(tmp);
		sum += dwarf[i];
	}

	int dif = sum - 100;
	bool ifBreak = false;
	for (int i = 0;i < NUM - 1;i++) {
		for (int j = i + 1;j < NUM;j++) {
			if (dwarf[i] + dwarf[j] == dif) {
				dwarf[i] = 0;
				dwarf[j] = 0;
				ifBreak = true;
				break;
			}
		}
		if (ifBreak)
			break;
	}

	sort(dwarf.begin(), dwarf.end());

	for (int i = 2;i < NUM;i++) {
		cout << dwarf[i] << endl;
	}

	return 0;
}