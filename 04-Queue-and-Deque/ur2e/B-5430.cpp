#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    cin >> T;
    
    string p, arr;
    deque<int> DQ;

    string temp;
    for(int i = 0; i < T; i++){
        cin >> p;
        cin >> n;
        cin >> arr;
        for(int i = 0; i<arr.length(); i++){
            if(arr[i] >= '0' && arr[i] <= '9'){
                temp += arr[i];
            }
            else if (arr[i] == ',' || arr[i] == ']') {
                if(!temp.empty()){
                    DQ.push_back(stoi(temp));
                    temp.clear();
                }
            }
            else if(arr[i] == '['){
                continue;
            }
        }

        bool isNotError = true;
        bool isNotReverse = true;
        for(int i = 0; i < p.length(); i++){
            if(p[i] == 'R'){
                isNotReverse =!isNotReverse;
            }
            else{ // 'D'
                if(DQ.empty()){
                    isNotError = false;
                    cout << "error\n";
                    break;
                }
                else
                {
                    if(isNotReverse){
                        DQ.pop_front();
                    } 
                    else{
                        DQ.pop_back();
                    }
                }
            }  
        }
        if(isNotError){
            if(isNotReverse){
                cout << "[";
                while(!DQ.empty()){
                    cout << DQ.front();
                    DQ.pop_front();
                    if(!DQ.empty())
                        cout << ",";
                }
                cout << "]\n";
            }
            else{
                cout << "[";
                while(!DQ.empty()){
                    cout << DQ.back();
                    DQ.pop_back();
                     if(!DQ.empty())
                        cout << ",";
                }
                cout << "]\n";
            }
        }
    }

    return 0;
}
