#include <iostream>
using namespace std;

int main(){
    int *weight, *height, *rank;
    int arr_size;

    cin >> arr_size;

    weight = new int[arr_size];
    height = new int[arr_size];
    rank = new int[arr_size];

    for(int i = 0; i < arr_size; i++){
        cin >> weight[i] >> height[i];
    }

    for(int i = 0; i < arr_size-1; i++){
        for(int j = i; j < arr_size; j++){
            if( (weight[i] < weight[j]) && (height[i] < height[j]) ) rank[i]++;
            else if ((weight[i] > weight[j]) && (height[i] > height[j]) ) rank[j]++;
        }
    }

    for(int i = 0; i < arr_size; i++){
        cout << rank[i]+1 << " ";
    }
    delete[] weight;
    delete[] height;
    delete[] rank;

    return 0;
}