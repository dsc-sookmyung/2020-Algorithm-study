// 바이러스
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[101];
int c[101];
int virus = -1;  // except "1"

void dfs(int x) {
	if (c[x]) return;
	c[x] = true;
	virus++;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		dfs(y);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	int v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	dfs(1);
	cout << virus;
}