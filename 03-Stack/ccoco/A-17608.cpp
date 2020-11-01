#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    stack<int> s;
    int n;
    scanf("%d\n", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        s.push(arr[i]);
    }
    printf("%lu", s.size());
    return 0;
}
