#include <iostream>

using namespace std;

int N, k;
int arr[1048577];
int tmp[1048577];

void merge(int begin, int end) {
	/* ������ ����Ʈ�� ũ��� merge�� ���� ���� Ŀ���Ƿ�,
	   -> ������ ����Ʈ�� ũ�� > k���� ������ ����Ʈ�� ũ��
	   �� �Ǳ� �������� merge�� �������ָ� 
	   k���� ������ �������� ���� �� �ִ�. */
	if (end - begin > N / k) return;
	int mid = (begin + end) / 2;
	int left_index = begin;
	int right_index = mid;
	for (int i = begin; i < end; i++) {
		if (right_index == end) tmp[i] = arr[left_index++];
		else if (left_index == mid) tmp[i] = arr[right_index++];
		else if (arr[left_index] <= arr[right_index]) tmp[i] = arr[left_index++];
		else tmp[i] = arr[right_index++];
	}
	for (int i = begin; i < end; i++) arr[i] = tmp[i];
}

void merge_sort(int begin, int end) {
	if (end == begin + 1) return;
	int mid = (begin + end) / 2;
	merge_sort(begin, mid);
	merge_sort(mid, end);
	merge(begin, end);
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> k;

	merge_sort(0, N);
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
}