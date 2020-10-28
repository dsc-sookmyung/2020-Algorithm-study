#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

struct student{
	string name;
	int kor, eng, math;
};

bool compare(student a, student b) {
	if(a.kor == b.kor) { // 국어 점수 같다
		if(a.eng == b.eng){ // 국영 점수 같다
			if(a.math == b.math){ // 국영수 같다
				return a.name < b.name;	
			}
			else { // 수학 내림차순
				return a.math > b.math;
			}
		}
		else{ // 영어 오름차순
			return a.eng < b.eng;
		}
	}
	else {
		return a.kor > b.kor;
	}
}

int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int num;
	cin >> num;
	
	string name;
	int kor, eng, math;

	vector<student> v(num);

	for(int i = 0 ; i < num; i++){
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}
	
	sort(v.begin(), v.end(), compare);

	
	for(int i = 0; i < num; i++){
		cout << v[i].name << '\n';
	}
	
	return 0;
}

