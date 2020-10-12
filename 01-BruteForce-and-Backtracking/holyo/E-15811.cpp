#include <iostream>
#include <string>

using namespace std;

const int MAX = 10;
int n;
int answer[MAX];
char sign[MAX][MAX];

void go(int index) {
    if (index == n) return;
    for (int value = -10; value <= 10; value++) {
        for (int i = index; i >= 0; i--) {
            char s = sign[i][index];
            
        }
    }
}

int main() {
    cin >> n;
    
    string input;
    cin >> input;
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sign[i][j] = input[index++];
        }
    }
    
    return 0;
}
