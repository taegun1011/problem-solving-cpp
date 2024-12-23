#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//No. 19 [Professional] 단어가 등장하는 횟수

int solve() {
	string B, S;
	cin >> B >> S;

	int slen = S.length(), blen = B.length();

	//32 37 41이라네요.. ㅎㅎ
	int hash37 = 0, hash41 = 0, hash47 = 0;

	//ASCII 값을 그대로 곱해줘야 제대로 해싱 가능
	for (char ch : S) {
		hash37 = hash37 * 37 + ch;
		hash41 = hash41 * 41 + ch;
		hash47 = hash47 * 47 + ch;
	}

	//오버플로우는 배열에 인덱싱해야 할 때만 신경써도 된다
	int ans = 0;
	int mul37 = 0, mul41 = 0, mul47 = 0, pow37 = 0, pow41 = 0, pow47 = 0;
	for (int i = 0; i < slen; i++) {
		mul37 = mul37 * 37 + B[i];
		mul41 = mul41 * 41 + B[i];
		mul47 = mul47 * 47 + B[i];
		pow37 = pow37 ? pow37 * 37 : 1;
		pow41 = pow41 ? pow41 * 41 : 1;
		pow47 = pow47 ? pow47 * 47 : 1;
	}
	if (mul37 == hash37 && mul41 == hash41 && mul47 == hash47)
		ans++;

	
	for (int i = slen; i < blen; i++) {
		mul37 = (mul37 - B[i - slen] * pow37) * 37 + B[i];
		mul41 = (mul41 - B[i - slen] * pow41) * 41 + B[i];
		mul47 = (mul47 - B[i - slen] * pow47) * 47 + B[i];
		if (mul37 == hash37 && mul41 == hash41 && mul47 == hash47)
			ans++;
	}

	return ans;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		printf("#%d %d\n", tc, solve());
	}
}