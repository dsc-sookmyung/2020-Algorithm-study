#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    
    int body[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &body[i][0], &body[i][1]);
    }
    
    for (int i = 0; i < n; i++) {
        int cnt_bigger = 0;
        for (int j = 0; j < n; j++) {
            if (body[i][0] < body[j][0] && body[i][1] < body[j][1]) cnt_bigger++;
        }
        printf("%d ", cnt_bigger + 1);
    }
    
    return 0;
}
