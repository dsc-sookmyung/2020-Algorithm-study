#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int x[n];
    vector<int> x_sort(n);
    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);
        x[i] = input;
        x_sort[i] = input;
    }
    
    sort(x_sort.begin(), x_sort.end());
    x_sort.erase(unique(x_sort.begin(), x_sort.end()), x_sort.end());
    
    map<int, int> comp;
    for (int i = 0; i < x_sort.size(); i++) {
        comp.insert(pair<int, int>(x_sort[i], i));
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", comp[x[i]]);
    }
    
    return 0;
}
