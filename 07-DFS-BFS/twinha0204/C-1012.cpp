#include <iostream>

using namespace std;

void DFS(bool** board, bool** visited, int i, int j, int N, int M) {
	visited[i][j] = true;
	if ((i < N - 1) && (board[i + 1][j]) && !(visited[i + 1][j])) {
		DFS(board, visited, i + 1, j, N, M);
	}
	if ((j < M - 1) && (board[i][j + 1]) && !(visited[i][j + 1])) {
		DFS(board, visited, i, j + 1, N, M);
	}
	if ((i > 0) && (board[i - 1][j]) && !(visited[i - 1][j])) {
		DFS(board, visited, i - 1, j, N, M);
	}
	if ((j > 0) && (board[i][j - 1]) && !(visited[i][j - 1])) {
		DFS(board, visited, i, j - 1, N, M);
	}
}

int main() {
	int T;
	cin >> T;
	for (int it = 0;it < T;it++) {
		int M, N, K;
		cin >> M >> N >> K;
		
		bool** farm = new bool*[N];
		for (int i = 0;i < N;i++)
			farm[i] = new bool[M]();

		for (int i = 0;i < K;i++) {
			int x, y;
			cin >> x >> y;
			farm[y][x] = true;
		}

		bool** visited = new bool*[N];
		for (int i = 0;i < N;i++)
			visited[i] = new bool[M]();

		// DFS
		int count = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (farm[i][j] && !(visited[i][j])) {
					DFS(farm, visited, i, j, N, M);
					count++;
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}