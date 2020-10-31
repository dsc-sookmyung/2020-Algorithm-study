//막대기
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int barNum = 0, visibleBarsNum = 1;
    cin >> barNum;
    int bars[barNum];

    for (int i = 0; i < barNum; i++)
        cin >> bars[i];
    int tallestBar = bars[barNum - 1];
    for (int i = barNum - 2; i >= 0; i--)
    {
        if (bars[i] > tallestBar)
        {
            visibleBarsNum++;
            tallestBar = bars[i];
        }
    }

    cout << visibleBarsNum << endl;
}