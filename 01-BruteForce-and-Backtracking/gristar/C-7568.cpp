#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<int,int>> v;
vector<int> answer;

void solution(int idx){
	int cnt=0;
	
	for(int i=0;i<v.size();i++){
		if(i==idx)
			continue;
		if(v[idx].first<v[i].first&&v[idx].second<v[i].second)
			cnt++;
	}
	answer.push_back(cnt);
}

int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		
		v.push_back(make_pair(x,y));
	}
	
	for(int i=0;i<n;i++)
		solution(i);
	
	for(int i=0;i<n;i++)
		cout<<answer[i]+1<<' ';
}