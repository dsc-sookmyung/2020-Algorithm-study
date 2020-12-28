#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int d[n];
    memset(d, 0, sizeof(d));
    
    d[0] = 1;
    d[1] = 2;
    
    for (int i = 2; i < n; i++) {
        d[i] = (d[i - 1] + d[i - 2]) % 10007;
    }
    
    cout << d[n - 1] << '\n';
    return 0;
}
