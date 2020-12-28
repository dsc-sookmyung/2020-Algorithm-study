// 연구소
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;


int N, M;
int safe = -3;	// 나중에 추가할 벽 3개
int minVal = 70;
int a[8][8];
bool visited[8][8];
vector<pair<int, int>> v;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int dfs(int x, int y) {
	int res = 1;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (visited[nx][ny] || a[nx][ny]) continue;
		res += dfs(nx, ny);
	}
	return res;
}

void sol(int wall, int x, int y) {
	if (wall == 3) {
		int cnt = 0;
		memset(visited, 0, sizeof(visited)); // visited = {0, } not working
		for (auto k : v) {
			cnt += dfs(k.first, k.second);
		}
		if (minVal > cnt) {
			minVal = cnt;
		}
		return;
	}
	for (int i = x; i < N; i++) {
		int k;
		if (i == x) k = y;
		else k = 0;
		
		for (int j = k; j < M; j++) {
			if (a[i][j] == 0) {
				a[i][j] = 1;
				sol(wall+1, i, j + 1);
				a[i][j] = 0;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	int x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> x;
			a[i][j] = x;
			if (x != 1) safe++;
			if (x == 2) v.push_back({ i, j });
		}
	}
	sol(0, 0, 0);
	cout << safe - minVal;
}
