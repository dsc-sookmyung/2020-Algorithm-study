//제로
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int k;
    cin >> k;
    stack<int> st;
    while (k--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            st.pop();
        }
        else
        {
            st.push(x);
        }
    }
    int sum = 0;
    int size = st.size();
    if (size == 0)
        cout << 0;
    else
    {
        while (size--)
        {
            sum += st.top();
            st.pop();
        }
        cout << sum;
    }
}