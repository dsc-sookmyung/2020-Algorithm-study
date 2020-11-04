#include <iostream>
#include <stack>

using namespace std;

int main(){
	int N, h;
	cin >> N;

	stack<int> heights;
	for(int i=0;i<N;i++){
		cin >> h;
		while(!heights.empty() && heights.top() <= h){
			heights.pop();
		}
		heights.push(h);
	}

	cout << heights.size() << endl;

	return 0;
}