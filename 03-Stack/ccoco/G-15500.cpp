#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    stack<int> s1, s2, s3;
    int n, tmp;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;  s1.push(tmp);
    }
    while (!s1.empty() || !s2.empty()) {
        int a = 0;
        int to;
        if (!s1.empty() && !s2.empty()) {
            if (s1.top() > s2.top()) {
                to = 1; a = s1.top();
                s1.pop();
            } else {
                to = 2; a = s2.top();
                s2.pop();
            }
        } else if (!s1.empty()) {
            to = 1; a = s1.top();
            s1.pop();
        } else {
            to = 2; a = s2.top();
            s2.pop();
        }
        while (!s3.empty() && s3.top() < a) {
            int b = s3.top();
            s3.pop(); s2.push(b);
            v.push_back(make_pair(3, 2));
        }
        s3.push(a);
        v.push_back(make_pair(to, 3));
    }
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }
    return 0;
}
