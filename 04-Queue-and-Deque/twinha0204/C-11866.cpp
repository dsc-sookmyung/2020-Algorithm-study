#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int* list = new int[N]();
	// list를 1번부터 N번까지로 초기화
	for (int i = 0;i < N;i++) {
		list[i] = i + 1;
	}

	int index = -1;
	string result = "<";
	// 
	for (int i = 0;i < N;i++) {

		// 원에 남은 사람 중에 제거할 다음 사람 찾기
		for (int j = 0;j < M;j++) {
			index = (index + 1) % N;
			while (list[index] == 0) {
				index = (index + 1) % N;
			}
		}
		
		// 조세퍼스 순열에 추가
		result += to_string(list[index]);
		if (i < N - 1) {
			result += ", ";
		}
		else {
			result += ">";
		}

		// 원에서 제거
		list[index] = 0;
	}

	cout << result;

	delete[] list;

	return 0;
}