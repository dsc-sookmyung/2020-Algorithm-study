#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int kor, eng, math;
};

bool priority(student s1, student s2) {
    if (s1.kor == s2.kor) {
        if (s1.eng == s2.eng) {
            if (s1.math == s2.math) {
                return s1.name < s2.name;
            }
            else return s1.math > s2.math;
        }
        else return s1.eng < s2.eng;
    }
    else return s1.kor > s2.kor;
}

int main() {
    int n;
    cin >> n;
    
    student students[n];
    
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;
    }
    
    sort(students, students + n, priority);

    for (int i = 0; i < n; i++) {
        cout << students[i].name << '\n';
    }
    
    return 0;
}
