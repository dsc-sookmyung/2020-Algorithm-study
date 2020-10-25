// 국영수
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Students
{
    string name;
    int kor;
    int eng;
    int math;
};

bool compare(Students stu1, Students stu2)
{
    if (stu1.kor > stu2.kor)
        return true;
    else if (stu1.kor == stu2.kor)
    {
        if (stu1.eng < stu2.eng)
            return true;
        else if (stu1.eng == stu2.eng)
        {
            if (stu1.math > stu2.math)
                return true;
            else if (stu1.math == stu2.math)
                return stu1.name < stu2.name;
        }
    }
    return false;
}

int main()
{
    int N;
    scanf("%d", &N);
    Students stu[N];

    for (int i = 0; i < N; i++)
        cin >> stu[i].name >> stu[i].kor >> stu[i].eng >> stu[i].math;
    sort(stu, stu + N, compare);

    for (int i = 0; i < N; i++)
        cout << stu[i].name << "\n";

    return 0;
}