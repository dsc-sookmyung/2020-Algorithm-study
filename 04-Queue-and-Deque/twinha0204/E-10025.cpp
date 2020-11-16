// 게으른 백곰 - 10025
#include <iostream>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int main(){
	int N, K;
	cin >> N >> K;

	map<int, int> m;
	for (int i=0;i<N;i++){
		int g, x;
		cin >> g >> x;
		m[x] = g;
	}

	queue<pair<int, int>> q;
	int max = 0, sum = 0;
	for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
		int idx = it->first;
		int val = it->second;
		while(!q.empty()){
			if(idx - q.front().first <= 2*K){
				q.push({idx, val});
				sum += val;
				break;
			}
			else{
				sum -= q.front().second;
				q.pop();
			}
		}
		if(q.empty()){
			q.push({idx, val});
			sum += val;
		}
		
		if(max < sum){
			max = sum;
		}
	}

	cout << max << endl;

	return 0;
}