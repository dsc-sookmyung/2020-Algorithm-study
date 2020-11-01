#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<int> stack;
string x;
int top = -1;

void command(string x, vector<int> &stack) {
	if (x == "push") {
		int num;
		cin >> num;
		top++;
		stack.push_back(num);
	}
	else if (x == "pop") {
		if (stack.empty()) {
			cout << -1 << '\n';
		}
		else {
			cout << stack[top] << '\n';
			stack.pop_back();
			top--;
		}
	}
	else if (x == "size") {
		cout << stack.size() << '\n';
	}
	else if (x == "empty") {
		if (stack.empty()) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	else if (x == "top") {
		if (stack.empty()) {
			cout << -1 << '\n';
		}
		else {
			cout << stack[top] << '\n';
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		command(x, stack);
	}
}