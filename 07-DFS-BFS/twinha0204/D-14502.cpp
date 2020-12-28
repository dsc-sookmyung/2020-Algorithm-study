#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> area(8, vector<int>(8));

void spreadVirus(vector<vector<int>> &v){
	queue<pair<int, int>> q;
	vector<vector<bool>> checked(N, vector<bool>(M, false));
	int dn[4] = {1, 0, -1, 0};
	int dm[4] = {0, 1, 0, -1};

	// 초기점 넣기
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(v[i][j] == 2){
				checked[i][j] = true;
				q.push({i, j});
			}
		}
	}

	// 바이러스 퍼뜨리기
	while(!q.empty()){
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();
		for(int dir = 0;dir < 4;dir++){
			int nexti = curi + dn[dir];
			int nextj = curj + dm[dir];
			if((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M) 
			&& !checked[nexti][nextj] && v[nexti][nextj] == 0){
				checked[nexti][nextj] = true;
				v[nexti][nextj] = 2;
				q.push({nexti, nextj});
			}
		}
	}
}

int getCount(vector<vector<int>> &v){
	int result = 0;
	spreadVirus(v);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(v[i][j] == 0){
				result++;
			}
		}
	}
	return result;
}

int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> area[i][j];
		}
	}

	// 조합 준비 작업
	vector<pair<int, int>> zeros;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(area[i][j] == 0){
				zeros.push_back({i, j});
			}
		}
	}
	vector<int> idx(zeros.size(), 0);
	for(int k=1;k<=3;k++){
		idx[idx.size()-k] = 1;
	}

	// 3개를 뽑아 벽세우기
	int maxArea = 0;
	do{
		vector<vector<int>> temp(area);
		for(int index = 0;index < idx.size(); index++){
			if(idx[index] == 1){
				int i = zeros[index].first;
				int j = zeros[index].second;
				temp[i][j] = 1;
			}
		}
		int tempResult = getCount(temp);
		if(maxArea < tempResult){
			maxArea = tempResult;
		}
	} while(next_permutation(idx.begin(), idx.end()));

	cout << maxArea << endl;

	return 0;
}