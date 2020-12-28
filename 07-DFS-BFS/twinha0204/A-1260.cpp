#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void DFS(bool** graph, int N, int V) {
	bool* visited = new bool[N]();
	stack<int> DFS;
	DFS.push(V);
	while (!(DFS.empty())) {
		// 현재 가장 위에 있는 것 출력
		int cur = DFS.top();
		DFS.pop();
		if (!(visited[cur])) {
			cout << cur + 1 << ' ';
			visited[cur] = true;
		}

		// 다음 순서 스택에 저장
		for (int i = N - 1;i >= 0;i--) {
			if (graph[cur][i] && !(visited[i])) {
				DFS.push(i);
			}
		}
	}
}

void BFS(bool** graph, int N, int V) {
	bool* visited = new bool[N]();
	queue<int> BFS;
	BFS.push(V);
	while (!(BFS.empty())) {
		// 현재 가장 위에 있는 것 출력
		int cur = BFS.front();
		BFS.pop();
		if (!(visited[cur])) {
			cout << cur + 1 << ' ';
			visited[cur] = true;
		}

		// 다음 순서 스택에 저장
		for (int i = 0;i < N;i++) {
			if (graph[cur][i] && !(visited[i])) {
				BFS.push(i);
			}
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	// 그래프를 표현할 자료구조 초기화
	bool** graph = new bool*[N];
	for (int i = 0;i < N;i++) {
		graph[i] = new bool[N]();
	}

	// 간선 입력 받기
	for (int i = 0;i < M;i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tmp1--;
		tmp2--;
		graph[tmp1][tmp2] = true;
		graph[tmp2][tmp1] = true;
	}

	// DFS 수행
	DFS(graph, N, V - 1);
	cout << endl;

	// BFS 수행
	BFS(graph, N, V - 1);
	cout << endl;

	return 0;
}