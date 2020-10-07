// 3258 - 컴포트
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, Z, M;
	cin >> N >> Z >> M;
    Z--;

	vector<bool> fields(N, true);
	for (int i = 0; i < M; i++)
	{
		int index;
		cin >> index;
		fields[index - 1] = false;
	}
	
	int k;
	for (k = 1; k < Z; k++){
		vector<bool> visited(N, false);
		int next = 0 + k;
		bool flag = false;
		while(!visited[next] && fields[next]){
			visited[next] = true;
			if(next == Z){
				flag = true;
				break;
			}
			next = (next + k) % N;
		}
		if(flag)
			break;
	}
	cout << k << endl;

	return 0;
}