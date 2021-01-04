// ½ÎÀÌ¹ö°³°­ÃÑÈ¸
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


string S, E, Q;
set<string> sIn;
set<string> sOut;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S >> E >> Q;

	string time, name;
	bool checkIn, checkOut;

	while (cin >> time >> name) {
		int hour = (time[0] - '0') * 10 + (time[1] - '0');
		int min = (time[3] - '0') * 10 + (time[4] - '0');
		int sHour = (S[0] - '0') * 10 + (S[1] - '0');
		int sMin = (S[3] - '0') * 10 + (S[4] - '0');
		int eHour = (E[0] - '0') * 10 + (E[1] - '0');
		int eMin = (E[3] - '0') * 10 + (E[4] - '0');
		int qHour = (Q[0] - '0') * 10 + (Q[1] - '0');
		int qMin = (Q[3] - '0') * 10 + (Q[4] - '0');
		checkIn = (0 <= hour && hour < sHour) || ((hour == sHour) && (0 <= min && min <= sMin));
		checkOut = (eHour < hour && hour < qHour) || ((eHour == hour && hour < qHour) && (eMin <= min))
			|| ((eHour < hour && hour == qHour) && (min <= qMin)) || ((eHour == hour && hour == qHour) && (eMin <= min && min <= qMin));

		if (checkIn) {
			sIn.insert(name);
		}
		else if (checkOut) {
			sOut.insert(name);
		}
	}

	vector<string> vAns(sIn.size() + sOut.size());
	auto iter = set_intersection(sIn.begin(), sIn.end(), sOut.begin(), sOut.end(), vAns.begin());
	vAns.erase(iter, vAns.end());

	cout << vAns.size();
}