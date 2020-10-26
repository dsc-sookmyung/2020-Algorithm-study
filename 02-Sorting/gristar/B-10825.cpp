#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Students{
	string name;
	int kor;
	int eng;
	int math;
};

bool cmp(Students a,Students b){
	if(a.kor>b.kor)
		return true;
	else if(a.kor==b.kor){
		if(a.eng<b.eng)
			return true;
		else if(a.eng==b.eng){
			if(a.math>b.math)
				return true;
			else if(a.math==b.math)
				if(a.name<b.name)
					return true;
		}
	}
	return false;
}

int main(){
	int n;

	scanf("%d",&n);
	Students stu[n];
	
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].kor>>stu[i].eng>>stu[i].math;		
	}
	
	sort(stu,stu+n,cmp);
	
	for(int i=0;i<n;i++){
		cout<<stu[i].name<<'\n';
	}
}