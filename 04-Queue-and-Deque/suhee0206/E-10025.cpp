#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Ice {
public:
	int g, x;
	Ice(int ng, int nx);
};

Ice::Ice(int ng, int nx) {
	g = ng;
	x = nx;
}

vector<Ice> v;

bool compare(const Ice& a, const Ice& b) {
	return a.x < b.x;
}

int N, k;
int sum = 0;

int main() {
	cin >> N >> k;

	for (int i = 0; i < N; i++) {
		int g, x;
		cin >> g >> x;
		v.push_back(Ice(g, x));
	}
	
	sort(v.begin(), v.end(), compare);

	int max = 0;

	int startIndex = 0;
	int startPos, endPos;
	startPos = v[startIndex].x;
	int startVal = v[startIndex].g;
	for (int i = 0; i < N; i++) {
		Ice ice = v[i];
		endPos = ice.x;
		sum += ice.g;

		while (endPos - startPos > 2 * k) {
			sum -= startVal;
			startIndex++;
			startPos = v[startIndex].x;
			startVal = v[startIndex].g;
		}

		if (sum > max) {
			max = sum;
		}
	}	
	
	cout << max;
}
