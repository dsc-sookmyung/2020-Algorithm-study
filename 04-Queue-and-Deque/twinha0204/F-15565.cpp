#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
	int N, K;
	cin >> N >> K;

	int min = 0;
	vector<int> v(N);
	for(int i=0;i<N;i++){
		cin >> v[i];
		if(v[i] == 1){
			min++;
		}
	}

	if(min < K){
		cout << -1 << endl;
		return 0;
	}

	min = v.size();
	int count = 0;
	queue<int> q;
	for(int i=0;i<N;i++){
		if(q.empty()){
			if(v[i] == 1){
				q.push(v[i]);
				count++;
			}
		}
		else{
			if(v[i] == 1){
				if(count >= K){
					q.pop();
					while(!q.empty() && q.front() != 1){
						q.pop();
					}
				}
				else{
					count++;
				}
			}
			q.push(v[i]);
		}

		if(count >= K && q.size() < min){
			min = q.size();
		}
	}

	cout << min << endl;

	return 0;
}