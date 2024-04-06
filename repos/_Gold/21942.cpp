#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

int day[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int difference(string A, string B) {
	int Amin = atoi(A.substr(14, 2).c_str());
	int Ahour = atoi(A.substr(11, 2).c_str());
	int Aday = atoi(A.substr(8, 2).c_str());
	int Amonth = atoi(A.substr(5, 2).c_str());
	Aday += day[Amonth - 1];

	int Bmin = atoi(B.substr(14, 2).c_str());
	int Bhour = atoi(B.substr(11, 2).c_str());
	int Bday = atoi(B.substr(8, 2).c_str());
	int Bmonth = atoi(B.substr(5, 2).c_str());
	Bday += day[Bmonth - 1];

	int Cmin = Bmin - Amin;
	int Chour = Bhour - Ahour;
	int Cday = Bday - Aday;

	if (Cmin < 0) {
		Cmin += 60;
		Chour -= 1;
	}

	if (Chour < 0) {
		Chour += 24;
		Cday -= 1;
	}

	return Cday * 1440 + Chour * 60 + Cmin;
}

int get_deadline(string DHM) {
	int M = atoi(DHM.substr(7, 2).c_str());
	int H = atoi(DHM.substr(4, 2).c_str());
	int D = atoi(DHM.substr(0, 3).c_str());

	return D * 1440 + H * 60 + M;
}

void solve() {
	int N, F;
	string DDDHHMM;

	cin >> N >> DDDHHMM >> F;
	int dl = get_deadline(DDDHHMM);

	map<string, string> record;
	map<string, ll> late;

	while (N-- > 0) {
		string date, time, item, name;
		cin >> date >> time >> item >> name;
		
		string key = item + ' ' + name;
		string value = date + ' ' + time;
		if (record.find(key) != record.end()) {
			//그냥 문자열로 해보자
			int diff = difference(record[key], value);
			int ex = diff - dl;
			if(ex > 0)
				late[name] += 1l * F * ex;
			record.erase(key);
		}
		else
			record[key] = value;
	}

	if (late.empty())
		cout << -1 << '\n';
	else {
		for (auto& p : late)
			cout << p.first << ' ' << p.second << '\n';
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}