//수 정렬하기
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int N, i;
    scanf("%d", &N);
    int *arr = new int[N];
    for (i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    for (i = 0; i < N; i++)
        printf("%d\n", arr[i]);
    delete[] arr;
    return 0;
}