#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define INF 1e9

void solve() {
	int N;
	cin >> N;

	vector<PII> arr(N);
	for (PII& p : arr)
		cin >> p.first >> p.second;
	sort(arr.begin(), arr.end());

	vector<int> lis(N, INF);

	//끝이 arr[i].second인 lis의 길이
	vector<int> len(N);

	for (int i = 0; i < N;i++) {
		PII p = arr[i];
		//겹치지 않는다는 조건이 있기 때문에 맞았지만 lb로 해야 맞다
		int pos = lower_bound(lis.begin(), lis.end(), p.second) - lis.begin();
		lis[pos] = p.second;
		len[i] = pos;
	}
	
	int ans = lower_bound(lis.begin(), lis.end(), INF) - lis.begin();
	cout << N - ans << endl;

	vector<bool> used(N);

	//경로를 이렇게 찾아야 하는 이유
	//lis 배열은 단순히 lis의 모든 원소를 가능한 작게 유지하는 기능만 수행하므로,
	//맨 끝에 위치한 최솟값이 배열의 맨 앞에 저장되는 것도 가능하다. 그러나 이 원소는 실제 해에 포함되지 않는다.

	//알고리즘이 모든 원소에 대해 한 번씩만 접근하기 때문에 원소가 저장되는 위치는 변하지 않는다.
	//따라서 각 원소에 대해 lis에 저장되는 위치를 기록한다.
	//해를 뒤에서부터 찾는 이유는 뒤쪽부터 시작했을 때 가장 먼저 선택되는 원소는 반드시 해에 포함됨이 보장되기 때문이다

	//예시
	//arr : 10 20 0 5 15 25
	//len : 1  2  1 2 3  4
	//앞에서부터 찾으면 10 20 15 25가 나온다
	for (int i = N - 1; i >= 0; i--) {
		if (len[i] + 1 == ans) {
			used[i] = true;
			ans--;
		}
	}

	for (int i = 0; i < N; i++)
		if (!used[i])
			cout << arr[i].first << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}