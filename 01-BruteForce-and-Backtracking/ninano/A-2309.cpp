#include <iostream>
#include <algorithm>
using namespace std;

int dwarf[9];
int sum = 0;

int isSumHundred()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - dwarf[i] - dwarf[j] == 100)
            {
                dwarf[i] = -1;
                dwarf[j] = -1;
                return 0;
            }
        }
    }
    return -1;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> dwarf[i];
        sum += dwarf[i];
    }

    isSumHundred();
    sort(dwarf, dwarf + 9);

    for (int i = 0; i < 9; i++)
    {
        if (dwarf[i] > 0)
        {
            cout << dwarf[i] << endl;
        }
    }
    return 0;
}