//스택
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> v;

bool Empty()
{
    return v.empty();
}

void Push(int _data)
{
    v.push_back(_data);
}

void Top()
{
    if (!Empty())
    {
        cout << v.back() << "\n";
    }
    else
    {
        cout << "-1\n";
    }
}

void Pop()
{
    if (!Empty())
    {
        cout << v.back() << "\n";
        v.pop_back();
    }
    else
    {
        cout << "-1\n";
    }
}

int Size()
{
    return v.size();
}

int main()
{
    int n, data;
    char cmd[6];
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", cmd);
        if (!strcmp(cmd, "push"))
        {
            scanf("%d", &data);
            Push(data);
        }
        else if (!strcmp(cmd, "top"))
        {
            Top();
        }
        else if (!strcmp(cmd, "pop"))
        {
            Pop();
        }
        else if (!strcmp(cmd, "size"))
        {
            cout << Size() << "\n";
        }
        else if (!strcmp(cmd, "empty"))
        {
            if (Empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
    }
    return 0;
}