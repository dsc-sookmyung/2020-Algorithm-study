#include <iostream>
#include <queue>

using namespace std;

void BFS(bool** &matrix, int N, int &count) {
	bool* visited = new bool[N]();
	queue<int> waiting;

	waiting.push(0);

	while (!(waiting.empty())) {
		// waiting에서 하나 빼기
		int cur = waiting.front();
		waiting.pop();

		// waiting에 다음 순서 추가
		for (int i = 0;i < N;i++) {
			// 방문한 적 없을 때 추가
			if (matrix[cur][i] && !(visited[i])) {
				waiting.push(i);
			}
		}

		// 출력 후 방문 체크
		if (!visited[cur]) {
			count++;
			visited[cur] = true;
		}
	}
}

int main() {
	int N, E;
	cin >> N >> E;

	bool** matrix = new bool*[N];
	for (int i = 0;i < N;i++)
		matrix[i] = new bool[N]();

	for (int i = 0;i < E;i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		matrix[x][y] = true;
		matrix[y][x] = true;
	}

	int count = 0;
	BFS(matrix, N, count);

	cout << count - 1;
	
	return 0;
}