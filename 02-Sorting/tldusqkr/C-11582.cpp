#include <iostream>

using namespace std;

int a[1048577];
int b[1048577];
int n, cnt, limit;
void my_merge(int s, int e) {
    if (e - s > n / limit)
        return;
    int mid = (s + e) / 2;
    int i = s, j = mid + 1, k = 0;
    while (i <= mid && j <= e) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= e)
        b[k++] = a[j++];
    for (int i = s; i <= e; i++)
    a[i] = b[i - s];
}

void merge_sort(int s, int e) {
    if (s == e) return;
    int mid = (s + e) / 2;
    merge_sort(s, mid);
    merge_sort(mid + 1, e);
    my_merge(s, e);
}
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    cin >> limit;
    merge_sort(0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
