#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.sync_with_stdio(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int i;

	string* arr = new string[n + 1];
	map<string, int> M;
	string name;

	for (i = 1; i <= n; i++) {
		cin >> name;
		M.insert({ name, i });
		arr[i] = name;
	}

	for (i = 0; i < m; i++) {
		cin >> name;
		//숫자인 경우
		if (name[0] >= '0' && name[0] <= '9')
			cout << arr[atoi(name.c_str())] << '\n';

		//문자열인 경우
		else
			cout << M[name] << '\n';
	}
}