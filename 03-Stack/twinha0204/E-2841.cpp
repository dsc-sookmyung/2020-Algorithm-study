#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	int N, P, line, fret;
	cin >> N >> P;

	int count = 0;
	vector<stack<int>> fingers(6, stack<int>());
	for(int i=0;i<N;i++){
		cin >> line >> fret;
		while(!fingers[line-1].empty() && fret < fingers[line-1].top()){
			fingers[line-1].pop();
			count++;
		}
		if(fingers[line-1].empty() || fingers[line-1].top() != fret){
			fingers[line-1].push(fret);
			count++;
		}
	}
	cout << count << endl;

	return 0;
}