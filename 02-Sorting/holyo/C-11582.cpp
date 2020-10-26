#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int chicken[1'049'000];
int sorting[1'049'000];

void merge(int first, int last) {
    if (last - first > n / k) return;
    
    int mid = (first + last) / 2;
    int l = first;
    int r = mid + 1;
    int i = first;
    
    while (l <= mid && r <= last) {
        if (chicken[l] <= chicken[r]) sorting[i++] = chicken[l++];
        else sorting[i++] = chicken[r++];
    }
    
    while (l <= mid) sorting[i++] = chicken[l++];
    while (r <= last) sorting[i++] = chicken[r++];
    for (int i = first; i <= last; i++) chicken[i] = sorting[i];
}

void merge_sort(int first, int last) {
    if (first == last) return;
    
    int mid = (first + last) / 2;
    merge_sort(first, mid);
    merge_sort(mid + 1, last);
    merge(first, last);
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &chicken[i]);
    }
    
    scanf("%d", &k);
    
    merge_sort(0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", sorting[i]);
    }

    return 0;
}
