#include<iostream>
#include<algorithm>
using namespace std;

#define NUM 9
#define SUM 100

int arr[NUM];

int getNine(const int* arr) {
	int sum = 0;
	for (int i = 0; i < NUM; i++) {
		sum += arr[i];
	}
	return sum;
}

void getSeven(int *arr) {
	int sum = getNine(arr);
	for (int i = 0; i < NUM - 1; i++) {
		for (int j = i + 1; j < NUM; j++) {
			if (sum - (arr[i] + arr[j]) == SUM) {
				arr[i] = 0;
				arr[j] = 0;
				//* 한 쌍만 찾고 끝내야함!
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < NUM; i++) {
		cin >> arr[i];
	}
	
	getSeven(arr);
	sort(arr, arr + NUM);
	
	for (int i = 2; i < NUM; i++) {
		cout << arr[i] << endl;;
	}
}