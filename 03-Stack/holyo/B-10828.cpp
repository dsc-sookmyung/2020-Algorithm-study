#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> a;
    while (n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push"){
            int num;
            cin >> num;
            a.push(num);
        }
        else if (cmd == "top") {
            cout << (a.empty() ? -1 : a.top()) << endl;
        }
        else if (cmd == "size") {
            cout << a.size() << endl;
        }
        else if (cmd == "empty") {
            cout << a.empty() << endl;
        }
        else if (cmd == "pop") {
            cout << (a.empty() ? -1 : a.top()) << endl;
            if (!a.empty()) {
                a.pop();
            }
        }
    }
    return 0;
}
