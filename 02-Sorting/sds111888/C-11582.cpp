#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>a(n);

    for(int i =0; i<n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;

    int divide = 2;
    while(1)
    {
        if(divide > n)break;
        vector<vector<int>>s;
        s.resize(n/divide);
        int start = 0;
        int range = n/(n/divide);
        for(int i = 0; i<n/divide; i++)
        {
            for(int j =start; j<start+range; j++)
            {
                if(a.size() > j)
                {
                    s[i].push_back(a[j]);
                }

            }
            start+=range;
            sort(s[i].begin(), s[i].end());
        }

        a.clear();

        for(int i =0; i<n/divide; i++)
        {
            for(int j = 0; j<s[i].size(); j++)
            {
                a.push_back(s[i][j]);
            }
        }
        divide *=2;
        if(k > n/divide)break;
    }


    for(int i =0; i<a.size(); i++)
    {
        cout << a[i] << " ";
    }
}