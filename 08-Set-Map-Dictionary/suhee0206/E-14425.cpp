// 문자열 집합
#include <iostream>
#include <string>
#include <set>

using namespace std;


int N, M;
set<string> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (s.find(str) != s.end()) {
			ans = ans + 1;
		}
	}

	cout << ans;
}