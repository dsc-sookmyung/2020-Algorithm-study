#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    stack<int> s;
    
    scanf("%d", &n);
    
    while (n--) {
        int height;
        scanf("%d", &height);
        s.push(height);
    }
    
    int max_height = 0;
    int cnt_visible = 0;
    
    while (!s.empty()) {
        if (s.top() > max_height) {
            cnt_visible++;
            max_height = s.top();
        }
        s.pop();
    }
    
    printf("%d\n", cnt_visible);
    return 0;
}
