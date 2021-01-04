// 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <string>
#include <map>

using namespace std;


int N, M;
map<int, string> mKey;
map<int, string>::iterator itKey;
map<string, int> mVal;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	string name;
	for (int i = 1; i <= N; i++) {
		cin >> name;
		mKey[i] = name;
		mVal[name] = i;
	}


	string quest;
	for (int i = 0; i < M; i++) {
		cin >> quest;
		if (quest[0] >= 65) {	// 대문자로 시작할 경우 -> 입력 = value
			cout << mVal[quest] << '\n';
		}
		else {
			itKey = mKey.find(stoi(quest));
			cout << itKey->second << '\n';
		}
	}
}