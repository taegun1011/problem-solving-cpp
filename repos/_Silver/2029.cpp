#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
vector<vector<int>> board(7, vector<int>(7));

int checkSquare(int len, int sr, int sc){

    //크기
    if(sr + 2 * len >= 7 || sc - 1 + 2 * len >= 7)
        return 0;

    //위
    for (int i = 0; i < len;i++)
        if(!board[sr][sc + i * 2])
            return 0;

    //왼쪽
    for (int i = 0; i < len;i++)
        if(!board[sr + 1 + i * 2][sc - 1])
            return 0;

    //아래
    for (int i = 0; i < len;i++)
        if(!board[sr + 2 * len][sc + i * 2])
            return 0;
    
    //오른쪽
    for (int i = 0; i < len;i++)
        if(!board[sr + 1 + i * 2][sc - 1 + 2 * len])
            return 0;

    return 1;
}

void solve() {
    vector<string> arr(10);
    for (int i = 0; i < 10;i++)
        cin >> arr[i];

    int A = 0, B = 0;

    for (int i = 0; i < 10;i++){
        switch (i % 3) {
            case 0:
                for (int j = 1; j < 11;j+=3)
                    if(arr[i][j] == '-'){
                        board[i / 3 * 2][j / 3 * 2 + 1] = 1;
                        A++;
                    }
                break;

            case 1:
                for (int j = 0; j < 11;j+=3)
                    if(arr[i][j] == '|'){
                        board[i / 3 * 2 + 1][j / 3 * 2] = 1;
                        A++;
                    }
                break;
            case 2:
                break;
        }
    }

    for (int i = 1; i <= 3;i++)
        for (int j = 0; j < 7;j+=2)
            for (int k = 1; k < 7;k+=2)
                B += checkSquare(i, j, k);

    cout << 24 - A << ' ' << B << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}