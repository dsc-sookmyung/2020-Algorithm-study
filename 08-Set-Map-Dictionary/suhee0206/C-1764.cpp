// µË∫∏¿‚
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
set<string> sEar;
set<string> sEye;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		sEar.insert(name);
	}
	for (int i = 0; i < M; i++) {
		cin >> name;
		sEye.insert(name);
	}

	vector<string> vAns(sEar.size() + sEye.size());
	auto iter = set_intersection(sEar.begin(), sEar.end(), sEye.begin(), sEye.end(), vAns.begin());
	vAns.erase(iter, vAns.end());
	
	int count = vAns.size();
	cout << count << '\n';
	for (int i = 0; i < count; i++) {
		cout << vAns[i] << '\n';
	}
}