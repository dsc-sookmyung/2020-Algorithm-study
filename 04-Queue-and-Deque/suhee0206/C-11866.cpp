#include <iostream>
#include <queue>

using namespace std;

int N, k;
queue<int> q;


void josephus(int N, int k) {
	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();

		if (!q.empty()) {
			cout << ", ";
		}
	}
	cout << ">";
}

int main() {
	cin >> N >> k;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	josephus(N, k);
}