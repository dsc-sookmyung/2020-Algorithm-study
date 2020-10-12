#include <iostream>
#include <algorithm>
using namespace std;

bool isHansoo(int input)
{
    if (input < 100)
    {
        return true;
    }
    int num100, num10, num1;
    num100 = input / 100;
    num10 = (input % 100) / 10;
    num1 = (input % 100) % 10;
    if (num100 - num10 == num10 - num1)
    {
        return true;
    }
    return false;
}

int main()
{
    int input, cnt = 0;
    cin >> input;
    for (int i = 1; i <= input; i++)
    {
        if (isHansoo(i))
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}