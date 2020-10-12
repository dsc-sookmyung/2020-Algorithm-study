#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        string str = to_string(i);
        int len = str.length();
        
        if (len == 1 || len == 2) {
            cnt++;
            continue;
        }
        
        int gap = str[1] - str[0];
        bool is_right = true;
        for (int j = 2; j < len; j++) {
            if (str[j] - str[j - 1] != gap) {
                is_right = false;
                break;
            }
        }
        
        if (is_right) cnt++;
    }
    
    printf("%d\n", cnt);
    return 0;
}
