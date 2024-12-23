#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int bit_count(int bit) {

	//¹Ýº¹¹® ¾²¸é È¿°ú ¶³¾îÁü...
	int mask[5] = { 0b01010101010101010101010101010101,
		0b00110011001100110011001100110011,
		0b00001111000011110000111100001111,
		0b00000000111111110000000011111111,
		0b00000000000000001111111111111111 };

	for (int i = 0; i < 5; i++)
		bit = (bit & mask[i]) + ((bit >> (1 << i)) & mask[i]);

	return bit;
}

void solve() {
	int antatica = 0;
	for (char ch : string("acint"))
		antatica |= 1 << (ch - 'a');

	int N, K;
	cin >> N >> K;

	vector<string> arr(N);
	for (auto& str : arr)
		cin >> str;

	int ans = 0;
	for (int bit = 0; bit < (1 << 26); bit++) {
		if ((bit & antatica) != antatica)
			continue;

		int cnt = 0;
		for (int bit2 = 1; bit2 <= bit; bit2 <<= 1)
			cnt += !!(bit & bit2);

		if (cnt != K)
			continue;
		//if (__popcnt(bit) != K)
		//	continue;

		cnt = 0;
		for (auto str : arr) {
			bool flag = true;
			for(char ch : str)
				if (!(bit & (1 << (ch - 'a')))) {
					flag = false;
					break;
				}

			if (flag)
				cnt++;
		}

		ans = max(ans, cnt);
	}

	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}