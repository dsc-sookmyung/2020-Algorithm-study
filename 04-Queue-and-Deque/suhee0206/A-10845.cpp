/* queue */
#include <iostream>

using namespace std;


int N;
int queue[10001];
string x;
int head = 0, tail = 0;

void command(string x, int queue[10001]) {
	int size = tail - head;

	if (x == "push") {
		int num;
		cin >> num;
		queue[tail++] = num;
	}
	else if (x == "pop") {
		if (size == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << queue[head] << '\n';
			head++;
		}
	}
	else if (x == "size") {
		cout << size << '\n';
	}
	else if (x == "empty") {
		if (size == 0) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	else if (x == "front") {
		if (size == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << queue[head] << '\n';
		}
	}
	else if (x == "back") {
		if (size == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << queue[tail - 1] << '\n';
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		command(x, queue);
	}
}