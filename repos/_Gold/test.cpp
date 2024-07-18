#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;

//dp[i][j] : i번째에 크기 j 컴포넌트를 만드는 최소 비용
int dp[31][31];
vector<int> arr;
int INF = 1e9;

int re_dp(int idx, int cur) {
    if (idx + 1 < cur)
        return INF;
    if (cur == 1)
        return 0;
    if (cur == 2)
        return 1 - arr[idx];
    int& ret = dp[idx][cur];
    if (ret != -1)
        return ret;

    ret = INF;
    for (int i = 1; i < cur; i++) {
        for (int j = 1; j < idx - 1; j++) {
            ret = min(ret, re_dp(idx - 1, i) + re_dp(j, cur - i) + (1 - arr[idx]) * i * (cur - i));
            //if (idx == 4) {
            //    cout << idx - 1 << ' ' << i << ' ' << j << ' ' << cur - i << ' ' << ret << endl;
            //    cout << dp[3][4] << endl;
            //}
            if (idx == 3 && cur == 4) {
                cout << idx - 1 << ' ' << i << ' ' << j << ' ' << cur - i << ' ' << ret << endl;
            }
        }
        for (int j = 1; j < idx - 1; j++) {
            if (idx == 2 && cur == 2) {
                cout << idx - 1 << ' ' << i << ' ' << j << ' ' << cur - i << ' ' << ret << endl;
            }
            ret = min(ret, re_dp(j, i) + re_dp(idx - 1, cur - i) + (1 - arr[idx]) * i * (cur - i));
            //if (idx == 4) {
            //    cout << j << ' ' << i << ' ' << idx - 1 << ' ' << cur - i << ' ' << ret << endl;
            //    cout << dp[3][4] << endl;
            //}
            if (idx == 3 && cur == 4) {
                cout << idx - 1 << ' ' << i << ' ' << j << ' ' << cur - i << ' ' << ret << endl;
            }
        }
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> N;
    arr = vector<int>(N);
    for (int i=1;i<N;i++)
        cin >> arr[i];
    cout << re_dp(N - 1, N) << endl;
}
