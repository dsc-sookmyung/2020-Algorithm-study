// DFS�� BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int N, M, V;
//* ũ�⸦ 1000���� �ϸ� overflow!!!
vector<int> a[1001];	// �ϳ��� ������ ����� �ٸ� ������ ����
int cd[1001];	// dfs visited
int cb[1001]; // bfs visited

void dfs(int x) {
	if (cd[x]) return;
	cd[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	cb[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!cb[y]) {
				q.push(y);
				cb[y] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> V;

	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		a[v1].push_back(v2);
		a[v2].push_back(v1);
	}

	for (int i = 1; i <= N; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(V);
	cout << '\n';
	bfs(V);
}