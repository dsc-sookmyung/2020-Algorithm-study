#include <iostream>
#include <stack>

using namespace std;

int main() {
    string input;
    cin >> input;
    
    int product = 1;
    int answer = 0;
    bool is_correct = true;
    stack<char> seq;
    
    for(int i = 0; i < input.length(); i++) {
        char bracket = input[i];
        if (bracket == '(') {
            seq.push('(');
            product *= 2;
        }
        else if (bracket == '[') {
            seq.push('[');
            product *= 3;
        }
        else if (bracket == ')') {
            if (seq.empty() || seq.top() != '(') {
                is_correct = false;
                break;
            }
            else {
                if (input[i - 1] == '(') answer += product;
                seq.pop();
                product /= 2;
            }
        }
        else {
            if (seq.empty() || seq.top() != '[') {
                is_correct = false;
                break;
            }
            else {
                if (input[i - 1] == '[') answer += product;
                seq.pop();
                product /= 3;
            }
        }
    }
    
    if (!is_correct || !seq.empty()) cout << "0\n";
    else cout << answer << '\n';
    
    return 0;
}
