// 걸그룹 마스터 준석이
#include <iostream>
#include <map>
#include <set>

using namespace std;


int N, M;
map<string, set<string>> m;
map<string, set<string>>::iterator itM;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	string team, member;
	int number;
	for (int i = 0; i < N; i++) {
		cin >> team >> number;
		set<string> s;
		for (int i = 0; i < number; i++) {
			cin >> member;
			s.insert(member);
		}
		m[team] = s;
	}

	string name;
	int type;
	for (int i = 0; i < M; i++) {
		cin >> name;
		cin >> type;

		if (type == 0) {
			// 팀 멤버 모두 출력
			itM = m.find(name);
			set<string>::iterator itS;
			for (itS = itM->second.begin(); itS != itM->second.end(); itS++) {
				cout << *itS << '\n';
			}
		}
		else if (type == 1) {
			// 팀 이름 출력
			for (itM = m.begin(); itM != m.end(); itM++) {
				if (itM->second.find(name) != itM->second.end()) {
					cout << itM->first << '\n';
				}
			}
		}
	}
}