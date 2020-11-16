#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> getDeque(string list, int size) {
	deque<int> result;

	string num = "";
	int length = list.length();
	for (int i = 1;i < length - 1;i++) {
		if (list[i] == ',') {
			result.push_back(stoi(num));
			num = "";
		}
		else if (i == length - 2) {
			num += list[i];
			result.push_back(stoi(num));
		}
		else
			num += list[i];
	}

	return result;
}

deque<int> getReverseDeque(deque<int> queue) {
	deque<int> result;
	int size = queue.size();
	for (int i = size - 1;i >= 0;i--) {
		result.push_back(queue[i]);
	}
	return result;
}

string getString(deque<int> queue) {
	int size = queue.size();
	string result = "[";
	
	for (int i = 0;i < size;i++) {
		result += to_string(queue[i]);
		if (i < size - 1)
			result += ",";
	}

	result += "]";
	return result;
}

int main() {
	int T;
	cin >> T;
	for (int it = 0;it < T;it++) {
		string func; // 수행할 함수들
		cin >> func;
		int n; // 배열 원소의 개수
		cin >> n;
		string input; // 배열 형태
		cin >> input;

		deque<int> queue = getDeque(input, n);
		bool reversed = false;
		bool error = false;

		// 함수들(R,D) 수행하기
		int length = func.length();
		for (int i = 0;i < length;i++) {
			if (func[i] == 'R') {
				reversed = !reversed;
			}
			else if (func[i] == 'D') {
				if (queue.size() == 0) {
					error = true;
					break;
				}
				
				if (reversed)
					queue.pop_back();
				else
					queue.pop_front();
			}
		}

		// 뒤집기 처리
		if (reversed)
			queue = getReverseDeque(queue);

		// 최종 결과 string 구하기
		string result;
		if (error)
			result = "error";
		else
			result = getString(queue);
		cout << result << endl;
	}
}