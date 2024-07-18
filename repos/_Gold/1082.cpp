#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve()
{
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int &x : arr)
		cin >> x;
	cin >> M;

	// 현재 돈으로 살 수 있는 번호 중 '사고 남은 돈으로 번호를 가장 많이 살 수 있는' 번호를 산다
	// 처음은 1~N-1까지

	int mx_num = 0, mx_val = 0;
	for (int i = 1; i < N; i++)
	{
		int left = M - arr[i];
		if (left < 0)
			continue;
		for (int j = 0; j < N; j++)
		{
			if (mx_val <= left / arr[j])
			{
				mx_val = left / arr[j];
				mx_num = i;
			}
		}
	}

    string ans = "";
	ans.push_back(mx_num + '0');
	if (mx_num)
	{
		M -= arr[mx_num];

		while (M > 0)
		{
			mx_num = -1;
			mx_val = 0;
			for (int i = 0; i < N; i++)
			{
				int left = M - arr[i];
				if (left < 0)
					continue;
				for (int j = 0; j < N; j++)
				{
					if (mx_val <= left / arr[j])
					{
						mx_val = left / arr[j];
						mx_num = i;
					}
				}
			}

			if(mx_num < 0)
				break;

			ans.push_back(mx_num + '0');
			M -= arr[mx_num];
		}

	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());

	cout << ans << endl;
}

int main()
{
	FASTIO;
	int TC = 1;
	// cin >> TC;
	while (TC--)
		solve();
}