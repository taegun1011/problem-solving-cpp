#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void print_paragraph(string& str) {
	int len = str.length();
	bool flag = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			if (i == 0 || i == len - 1 || flag)
				continue;
			flag = 1;
		}
		else
			flag = 0;
		cout << str[i];
	}
	cout << '\n';
}

void solve() {
	string str;
	getline(cin, str);

	int pos = 0, end;
	while ((pos = str.find("<div title=\"", pos)) != string::npos) {
		end = str.find("\">", pos);
		cout << "title : ";
		for (pos = pos + 12; pos < end; pos++)
			cout << str[pos];
		cout << '\n';
		pos += 2;

		string sub = "";
		while (1) {
			string tag = "";
			for (pos++; str[pos] != '>'; pos++)
				tag.push_back(str[pos]);
			if (tag == "/div")
				break;
			if (tag == "/p") {
				print_paragraph(sub);
				sub = "";
			}

			for (pos++; str[pos] != '<'; pos++)
				sub.push_back(str[pos]);
		}
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