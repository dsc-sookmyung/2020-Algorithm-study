#include <iostream> 
#include <deque> 
#include <queue> 
using namespace std; 
#define xMAX 1000000 
int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL); 
    int n, k; 
    int maxSum=0, tempSum=0, length=0; 
    cin >> n >> k; 
    int g, x; 
    int arr[xMAX + 2] = { 0, }; // 얼음의 양 저장함 
    for (int i = 0; i < n; i++) { 
        cin >> g >> x; // g는 얼음의 양, x는 양동이의 좌표 
        if (x > length) length = x; // 최대길이 
        arr[x] = g; // x좌표에는 얼음이 g 있음 
    } 
    queue<int> q; // 큐는 2k+1만큼의 길이여야 함 
    for (int i = 0; i <= length; i++) { 
        // 큐가 꽉 차있지 않으면 
        if (q.size() < 2 * k + 1) { 
            q.push(arr[i]); 
            tempSum += arr[i]; 
        } 
        else { 
            // 큐가 꽉 차있으면 
            // 일단 팝을 해주고 그 값을 뺌 
            tempSum -= q.front(); 
            q.pop(); // 새로운걸 넣고 그 값을 더함 
            q.push(arr[i]); 
            tempSum += arr[i]; 
        }
        if (maxSum < tempSum) maxSum = tempSum; 
    }
    cout << maxSum << "\n"; 
    
    return 0; 
}
