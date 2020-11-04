//괄호의 값
#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    stack<char> S;
    int ans = 0, temp = 1;
    bool flag = false;

    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '(':
            temp *= 2;
            S.push('(');
            break;
        case '[':
            temp *= 3;
            S.push('[');
            break;
        case ')':
            if (S.empty() || S.top() != '(')
            {
                flag = true;
                break;
            }
            if (s[i - 1] == '(')
                ans += temp;
            S.pop();
            temp /= 2;
            break;
        case ']':
            if (S.empty() || S.top() != '[')
            {
                flag = true;
                break;
            }
            if (s[i - 1] == '[')
                ans += temp;
            S.pop();
            temp /= 3;
            break;
        }
        if (flag)
            break;
    }
    if (flag || !S.empty())
        cout << 0 << '\n';
    else
        cout << ans << '\n';
}