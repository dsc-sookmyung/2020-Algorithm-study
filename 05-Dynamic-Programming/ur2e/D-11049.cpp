#include <iostream>

using namespace std;

/*
 * d[i][j] : i ~ j 행렬까지 계산 결과 중 가장 횟수가 적은 것 
 * d[i][j] := d[i][k] + d[k+1][j] + a * b * c // i, j마다 a, b, c는 달라진다.
 * k를 매개로 i ~ j까지 곱해줘야한다. 
 * 마지막의 abc는 최종 행렬 1개를 만들기 위한 곱
 * i == j 일땐 k 없음. 행렬 1개라는 소리니까 return 0
 * 
 * 점화식 > optimal 인가? 
 * 
 * 전체 엔트리 d[i][j] = O(N^2)
 * 마다 i~j까지인 k를 다 봐야함 = O(N^3)
 * 
 * 보통 dp를 풀면 for i = 0~N { for j = i~N } 이렇게 할텐데,,, 이렇게 하면 안된다.
 * 
 * 그래서 보통 i - j 사이의 길이가 짧은 것부터 채운다. 길이가 0인 것 부터 .. ?
 * for int l = 0; ; l < n 
 *  for int i = 0 ; i < n
 *      j = i + l;
 * 
 * 
 * 
 * a = d[i][0]
 * b = d[i][1] (X) b = d[k][1]
 * c = d[j][1]
*/

int d[505][505];
int arr[505][2];

int main(void){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n; 
    cin >> n;

    //이거 i=0부터로 바꿔보기. . ..   . .
    for(int i = 1; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    for(int i = 1; i < n; i++){
        d[i][i+1] = arr[i][0] * arr[i][1] * arr[i+1][1];
    }

    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n - l; i++){
            int j = i + l; 
            for(int k = i; k < j; k++){
                int res = d[i][k] + d[k+1][j] + arr[i][0] * arr[k][1] * arr[j][1];
                if(!d[i][j] || d[i][j] > res) d[i][j] = res;
            }
        }
    }
    cout << d[1][n] << '\n';

    return 0;
}
 