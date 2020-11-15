/* deque */
#include <iostream>
using namespace std;

const int MAX = 10000;
int deque[2*MAX + 1];
int head = MAX, tail = MAX;

int N;
string x;


int size() {
	return tail - head;
}

void push_front(int x) {
	deque[--head] = x;
}

void push_back(int x) {
	deque[tail++] = x;
}

int pop_front() {
	if (size() == 0) {
		return -1;
	}
	else {
		return deque[head++];
	}
}

int pop_back() {
	if (size() == 0) {
		return -1;
	}
	else {
		return deque[--tail];
	}
}

int front() {
	if (size() == 0) {
		return -1;
	}
	else {
		return deque[head];
	}
}

int back() {
	if (size() == 0) {
		return -1;
	}
	else {
		return deque[tail - 1];
	}
}

void test() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == "push_front") {
			int num;
			cin >> num;
			push_front(num);
		}
		else if (x == "push_back") {
			int num;
			cin >> num;
			push_back(num);
		}
		else if (x == "pop_front") {
			cout << pop_front() << '\n';
		}
		else if (x == "pop_back") {
			cout << pop_back() << '\n';
		}
		else if (x == "size") {
			cout << size() << '\n';
		}
		else if (x == "empty") {
			if (size() == 0) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (x == "front") {
			cout << front() << '\n';
		}
		else if (x == "back") {
			cout << back() << '\n';
		}
	}
}

int main() {
	test();
}