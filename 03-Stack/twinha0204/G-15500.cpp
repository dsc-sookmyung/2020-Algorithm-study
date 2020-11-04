#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

int main(){
	int N, temp;
	cin >> N;

	vector<bool> pos(N+1, 0);
	vector<stack<int>> v(2, stack<int>());
	for(int i=0;i<N;i++){
		cin >> temp;
		v[0].push(temp);
	}

	vector<pair<int, int>> result;
	for(int num=N;num>0;num--){
		int idx = pos[num];
		for(int cur=v[idx].top();cur != num;cur=v[idx].top()){
			pos[cur] = !idx;
			v[!idx].push(cur);
			v[idx].pop();
			result.push_back({idx+1, (!idx)+1});
		}
		v[idx].pop();
		result.push_back({idx+1, 3});
	}

	cout << result.size() << endl;
	for(int i=0;i<result.size();i++){
		cout << result[i].first << ' ' << result[i].second << endl;
	}

	return 0;
}