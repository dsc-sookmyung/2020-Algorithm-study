#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
int N, K;
int arr[1000010];
 
int main(void)
{    
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    
    int left = 1;
    int right = 1;
    int lionCnt = 0;
    int Min = 99999999;
    
    while(left <= right && right <= N+1)
    {
        if(lionCnt < K)
        {
            if(arr[right] == 1)
            {
                lionCnt++;
                right++;
            }
            else
            {
                right++;
            }
        }
        else if(lionCnt > K)
        {
            if(arr[left] == 1)
            {
                lionCnt--;
                left++;
            }
            else
            {
                left++;
            }
        }
        else if(lionCnt == K)
        {
            if(Min > right-left)
            {
                Min = right-left;
            }
            
            if(arr[left] == 1)
            {
                lionCnt--;
                left++;
            }
            else
            {
                left++;
            }
        }
    }
    if(Min == 99999999)
    {
        cout << -1;
    }
    else
    {
        cout << Min;    
    }   
    return 0;
}