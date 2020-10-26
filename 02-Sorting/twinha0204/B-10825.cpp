// 국영수 - 10825
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Student{
public:
	string name;
	int kor, eng, math;
	Student(string name, int kor, int eng, int math):name(name), kor(kor), eng(eng), math(math){}
};

bool compare(Student a, Student b){
	if (a.kor == b.kor){
		if (a.eng == b.eng){
			if(a.math == b.math){
				return a.name < b.name;
			}
			else
				return a.math > b.math;
		}
		else
			return a.eng < b.eng;
	}
	else
		return a.kor > b.kor;
}

int main(void){
	int N;
	scanf("%d", &N);

	char temp[11];
	int kor, eng, math;
	vector<Student> students;
	for(int i=0;i<N;i++){
		scanf("%s %d %d %d", temp, &kor, &eng, &math);
		string name(temp);
		students.push_back(Student(name, kor, eng, math));
	}

	sort(students.begin(), students.end(), compare);

	for(int i=0;i<N;i++){
		printf("%s\n", students[i].name.c_str());
	}

	return 0;
}