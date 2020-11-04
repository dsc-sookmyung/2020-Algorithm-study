#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    stack<char> s;
    char t;
    int cnt = 0;
    int piece = 0;
    char arr[100000];
    while ((t = getchar()) != '\n') {
        s.push(t);
    }
    char pre = ' ';
    while (!s.empty()) {
        char brac = s.top();
        s.pop();
        if (brac == ')') {
            if (s.top() != '(') {
                cnt++; piece++;
            } else
                piece += cnt;
        } else if (brac == '(' && pre != ')') {
            cnt--;
        }
        pre = brac;
    }
    printf("%d", piece);
    return 0;
}
