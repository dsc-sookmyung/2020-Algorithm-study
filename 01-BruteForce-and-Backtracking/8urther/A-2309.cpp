#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int sum = 0;
    int i, j, k, n = 9;
    int arr[9];

    for (i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + n);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                for (k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    cout << arr[k] << endl;
                }
                return 0;
            }
        }
    }

    return 0;
}