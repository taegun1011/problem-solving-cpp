#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	double points[6] = { 4.0,3.0,2.0,1.0,0.0,0.0 };

	double total = 0, sum = 0;
	for (int i = 0; i < 20; i++) {
		string name;
		double credit;
		string grade;
		cin >> name >> credit >> grade;
		if (grade == "F")
			grade += "0";
		else if (grade == "P")
			continue;
		char alpha = grade[0];
		char plus = grade[1];
		total += credit;
		sum += credit * (points[alpha - 'A'] + (plus == '+' ? 0.5 : 0));
	}
	printf("%f\n", sum / total);
}