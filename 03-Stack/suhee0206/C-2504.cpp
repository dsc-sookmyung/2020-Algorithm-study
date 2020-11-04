#include <iostream>
#include <stack>

using namespace std;

string s;

int result() {
	stack<char> bracket;
	int answer = 0;
	int tmp = 1;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			tmp *= 2;
			bracket.push(s[i]);
		}
		else if (s[i] == '[') {
			tmp *= 3;
			bracket.push(s[i]);
		}
		else {
			if (bracket.empty()) {
				return -1;
			}
			else if (s[i] == ')') {
				if (bracket.top() != '(') {
					return -1;
				}
				else {
					if (s[i - 1] == '(') {
						answer += tmp;
					}
					tmp /= 2;
				}
			}
			else if (s[i] == ']') {
				if (bracket.top() != '[') {
					return -1;
				}
				else {
					if (s[i - 1] == '[') {
						answer += tmp;
					}
					tmp /= 3;
				}
			}
			bracket.pop();
		}
	}

	if (!bracket.empty()) {
		return -1;
	}

	return answer;
}

int main() {
	cin >> s;

	int output = result();

	if (output == -1) {
		puts("0");
	}
	else {
		printf("%d", output);
	}
}