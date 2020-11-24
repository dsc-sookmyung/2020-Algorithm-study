#include <iostream>
  
using namespace std;

long long t[1050];
int main(void){
        int n;
        cin >> n;

        t[1] = 1;
        t[2] = 2;

        for(int i = 3; i <= n; i++){
                t[i] = t[i-1] + t[i-2];
                t[i] = t[i]%10007;
        }
        cout << t[n] << '\n';
        return 0;
}
