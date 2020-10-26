#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int lang, eng, math;

	Student(string name, int lang, int eng, int math) {
		this->name = name;
		this->lang = lang;
		this->eng = eng;
		this->math = math;
	}
};

bool compare(Student& a, Student& b) {
	if (a.lang == b.lang && a.eng == b.eng && a.math == b.math)
		return a.name < b.name;
	else if (a.lang == b.lang && a.eng == b.eng)
		return a.math > b.math;
	else if (a.lang == b.lang)
		return a.eng < b.eng;
	else
		return a.lang > b.lang;
}

int main() {
	int N;
	cin >> N;

	vector<Student> students;
	string name;
	int lang, eng, math;
	for (int i = 0; i < N; i++) {
		cin >> name >> lang >> eng >> math;
		students.push_back(Student(name, lang, eng, math));
	}

	sort(students.begin(), students.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << students[i].name << '\n';
	}
}