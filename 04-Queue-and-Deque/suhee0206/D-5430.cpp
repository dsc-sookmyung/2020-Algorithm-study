#include <iostream>
#include <deque>
#include <string>

using namespace std;

int T;
string p;
int n;
string arr;
deque<int> d;

class Error {};

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		d.clear();

		cin >> p;

		cin >> n;
		cin >> arr;

		arr = arr.substr(1, arr.size() - 2);

		bool reverse = false;

		try {
			if (n > 0) {
				int a = 0;
				int b = 0;
				for (; b < arr.length(); b++) {
					if (arr[b] == ',') {
						if (a < b) {
							d.push_back(stoi(arr.substr(a, b - a)));
							a = b + 1;
						}
					}
				}
				if (!d.empty()) {
					d.push_back(stoi(arr.substr(a)));
				}
				else {
					d.push_back(stoi(arr));
				}
			}

			for (int i = 0; i < p.length(); i++) {
				if (p[i] == 'R') {
					reverse = !reverse;
				}
				else if (p[i] == 'D') {
					if (d.empty()) {
						throw Error();
						break;
					}
					if (reverse == false) {
						d.pop_front();
					}
					else {
						d.pop_back();
					}
				}
			}

			cout << "[";
			while (d.size()) {
				if (reverse == false) {
					cout << d.front();
					d.pop_front();
				}
				else {
					cout << d.back();
					d.pop_back();
				}

				if (!d.empty()) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
		catch (Error) {
			cout << "error\n";
		}
	}
}