#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
	string str;

	map<string, int> M;
	int cnt = 0;
	//getline으로 받기
	while (getline(cin, str)) {
		M[str]++;
		cnt++;
	}

	for (const auto& p : M)
		printf("%s %.4f\n", p.first.c_str(), (double)p.second * 100 / cnt);
}