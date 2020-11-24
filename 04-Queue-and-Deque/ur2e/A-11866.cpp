#include<iostream>
#include<queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    queue<int> Q;
    cin >> n >> k;
    for(int i = 1; i < n+1; i++){
        Q.push(i);
    }
    cout << "<";

    while(!Q.empty()){
        for(int i = 0; i < k-1; i++){
            Q.push(Q.front());
            Q.pop();
        }
        cout << Q.front();
        Q.pop();
        if(!Q.empty()){
            cout << ", ";
        }
    }
    cout << ">" << '\n';
    return 0;
}