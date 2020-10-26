#include<iostream>
#include<vector>
using namespace std;


struct Data
{
	int weight;
	int height;
	int rank;
};

void comparision(const int N, vector<Data> &v) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i].weight < v[j].weight && v[i].height < v[j].height) {
				v[i].rank++;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	vector<Data> v;
	Data data;

	for (int i = 0; i < N; i++) {
		cin >> data.weight;
		cin >> data.height;
		data.rank = 1;

		v.push_back(data);
	}

	comparision(N, v);

	for (int i = 0; i < N; i++) {
		cout << v[i].rank << " ";
	}
}