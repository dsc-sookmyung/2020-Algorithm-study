#include <iostream>
using namespace std;

// 2자리까지 숫자는 모두 한수..
int main() {
    int num, a, b, c;
    int count = 0;
    cin >> num;

    if( num < 100 ) {
        cout << num;
        return 0;
    }
    else{
        if(num == 1000) num = 999;
        for(int i = 100; i <= num; i++){
            a = i/100;
            b = (i%100)/10;
            c = i%10;
            if ( (b-a) == (c-b) ){
                count++;
            }
        }
    }
    cout << count+99;
}