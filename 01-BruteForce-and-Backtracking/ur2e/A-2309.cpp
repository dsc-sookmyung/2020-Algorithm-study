#include <iostream>
using namespace std;

int main(void){
    int height[9] = {};
    int real[7] = {};
    int sum = 0;
    int over, over_idx1, over_idx2;


    for(int i = 0; i < 9; i++){
        cin >> height[i];
        sum += height[i];
    }

    over = sum - 100;
    for(int i = 0; i < 8; i++){
        for(int j = i+1; j < 9; j++){
            if(height[i] + height[j] == over){
                over_idx1 = i;
                over_idx2 = j;
                break;
            }
        }
    }

    int idx = 0;
    for(int i = 0; i < 9; i++){
        if(i == over_idx1 || i == over_idx2)    continue;
        real[idx] = height[i];
        idx++;
    }

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7-(i+1); j++){
            if(real[j] > real[j+1])
                swap(real[j], real[j+1]);
            }
        }
    for(int i = 0; i < 7; i++){
        cout<<real[i]<<endl;
    }
}

