#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

struct pos {
	ll x;
	ll y;
};

//CCW 알고리즘 : CCW 값이 하나라도 양수이면 교차하지 않는다
int ccw(pos a, pos b, pos c) {
	ll temp = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
	if (temp > 0)
		return 1;
	if (temp == 0)
		return 0;
	else
		return -1;
}

int main() {
	FASTIO;

	ll x1, x2, x3, x4;
	ll y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	int ccw1 = ccw({ x1, y1 }, { x2,y2 }, { x3,y3 }) * ccw({ x1,y1 }, { x2,y2 }, { x4,y4 });
	int ccw2 = ccw({ x3, y3 }, { x4,y4 }, { x1,y1 }) * ccw({ x3,y3 }, { x4,y4 }, { x2,y2 });

	int res = 1;
	
	if (ccw1 > 0 || ccw2 > 0)
		res = 0;
	else {
		//일직선
		if (ccw1 == 0 && ccw2 == 0) {
			pair<int, int> p1 = { x1, y1 };
			pair<int, int> p2 = { x2, y2 };
			pair<int, int> p3 = { x3, y3 };
			pair<int, int> p4 = { x4, y4 };

			if (p1 > p2)
				swap(p1, p2);

			if (p3 > p4)
				swap(p3, p4);

			if (p4 < p1 || p2 < p3)
				res = 0;
		}
	}

	cout << res << endl;
}

//하....