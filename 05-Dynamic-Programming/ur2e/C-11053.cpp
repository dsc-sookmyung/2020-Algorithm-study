// 가장 긴 증가하는 부분 수열
#include<iostream>

using namespace std;
int d[1050];

int main(void){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    int num[n];

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    d[0] = 1;
    int pivot, len = 1;
    int tmp = 0, tmpIdx = -1;
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(num[j] < num[i]){
                if( tmp < d[j]){ // max d[j]
                    tmp = d[j];
                }
            }
        }
        d[i] = tmp + 1;
        /*
        if(tmpIdx == -1){ // 증가 수열 만들 수 x
            d[i] = 1;
        }
        else{ 
            d[i] = d[tmpIdx] + 1; 
        }
        */
        if(len < d[i]) len = d[i]; // 최대 길이 구하기
        
        tmp  = 0;
        tmpIdx = -1;
    }

    cout << len << '\n';
    return 0;
}

// 1 \n 1을 입력하면 0이 나오는 것까지 수정
// 7 \n 1 4 5 2 3 4 5 수정
