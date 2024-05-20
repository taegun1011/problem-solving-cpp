#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//No. 21 ¿°¶ó´ë¿ÕÀÇ ÀÌ¸§ Á¤·Ä

int tc = 1;
vector<string> arr;
vector<string> sorted_arr;

bool compare(string& a, string& b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	return a < b;
}

void merge_sort(int s, int e) {
	if (s == e)
		return;
	int m = (s + e) / 2;
	merge_sort(s, m);
	merge_sort(m + 1, e);
	
	int l = s, r = m + 1, cur = s;
	while (l <= m && r <= e)
		sorted_arr[cur++] = compare(arr[l], arr[r]) ? arr[l++] : arr[r++];

	while (l <= m)
		sorted_arr[cur++] = arr[l++];

	while (r <= e)
		sorted_arr[cur++] = arr[r++];

	for (int i = s; i <= e; i++)
		arr[i] = sorted_arr[i];
}

void solve() {
	int N;
	cin >> N;
	
	arr = vector<string>(N);
	sorted_arr = vector<string>(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	merge_sort(0, N - 1);

	cout << '#' << tc << '\n';

	string prv = "";
	for (string& str : arr) {
		if (str == prv)
			continue;
		cout << str << '\n';
		prv = str;
	}
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	while (tc <= TC) {
		solve();
		tc++;
	}
}