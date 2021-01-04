// ปýลยวะ
#include <iostream>
#include <string>
#include <map>

using namespace std;


map<string, int> mSpecies;
map<string, int>::iterator it;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	float count = 0;
	string species;
	while (getline(cin, species)) {
		if (mSpecies.find(species) == mSpecies.end()) {
			mSpecies[species] = 1;
		}
		else {
			mSpecies[species]++;
		}
		count = count + 1;
	}

	cout << fixed;
	cout.precision(4);
	for (it = mSpecies.begin(); it != mSpecies.end(); it++) {
		cout << it->first << " " << (it->second / count) * 100 << '\n';
	}
}