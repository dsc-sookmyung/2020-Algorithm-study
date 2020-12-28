// 유기농 배추
#include <iostream>

using namespace std;

int T;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int M, N;

void dfs(int a[50][50], int x, int y) {
	if (a[x][y] == 0)
		return;
	a[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			dfs(a, nx, ny);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int a[50][50] = { 0, };	// 초기화 꼭 필요
		// int a[50][50];

		int K;
		cin >> M >> N >> K;

		int X, Y;
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			a[X][Y] = 1;
		}

		/* test 시작
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				cout << "a1: " << a[x][y] << endl;
			}
		}
		test 끝 */

		int ans = 0;
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (a[x][y] == 1) {
					dfs(a, x, y);
					ans++;
				}
			}
		}

		cout << ans << '\n';
	}
}