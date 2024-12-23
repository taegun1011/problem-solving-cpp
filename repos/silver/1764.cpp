#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	cout.sync_with_stdio(0);


	int listen, see, i;
	cin >> listen >> see;

	map<string, int> L, L_S;
	string name;
	for (i = 0; i < listen; i++) {
		cin >> name;
		L.insert({ name, 1 });
	}

	for (i = 0; i < see; i++) {
		cin >> name;
		if (L[name])
			L_S.insert({ name,1 });
	}

	int l_s = L_S.size();

	cout << l_s << '\n';
	for (map<string, int>::iterator iter = L_S.begin(); iter != L_S.end(); iter++)
		cout << (*iter).first << '\n';

}