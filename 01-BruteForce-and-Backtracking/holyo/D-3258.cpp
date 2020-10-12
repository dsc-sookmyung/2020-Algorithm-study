#include <iostream>

const int MAX = 1001;
bool obstacle[MAX];

int main() {
    int n, z, m;
    scanf("%d %d %d", &n, &z, &m);
    
    while (m--) {
        int input;
        scanf("%d", &input);
        obstacle[input] = true;
    }
    
    for (int k = 1; k < z; k++) {
        int curr = 1;
        while (true) {
            curr = (curr + k) % n;
            if (curr == 0) curr = n;
            if (obstacle[curr] || curr == 1) break;
            if (curr == z) {
                printf("%d\n", k);
                return 0;
            }
        }
    }
    
    return 0;
}
