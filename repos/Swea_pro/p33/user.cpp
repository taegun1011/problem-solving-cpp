#include <vector>
#include <queue>

using namespace std;

struct Robot {
	bool isBroken;
	int iq;
	int job;
} robots[50001];

struct Job {
	vector<int> robots;
	int startedAt;
} jobs[50001];

struct Pair {
	int id;
	int iq;
};

class swap_if_low {
public:
	bool operator() (Pair p1, Pair p2) {
		if(p1.iq == p2.iq)
			return p1.id > p2.id;
		return p1.iq < p2.iq;
	}
};

class swap_if_high {
public:
	bool operator() (Pair p1, Pair p2) {
		if (p1.iq == p2.iq)
			return p1.id > p2.id;
		return p1.iq > p2.iq;
	}
};

priority_queue<Pair, vector<Pair>, swap_if_low> maxH;
priority_queue<Pair, vector<Pair>, swap_if_high> minH;

void init(int N)
{
	for (int i = 0;i <= 50000;i++) {
		robots[i] = { false, 0, 0 };
		jobs[i] = { vector<int>(), 0 };
	}

	maxH = priority_queue<Pair, vector<Pair>, swap_if_low>();
	minH = priority_queue<Pair, vector<Pair>, swap_if_high>();

	for (int i = 1;i <= N;i++) {
		maxH.push({ i, 0 });
		minH.push({ i, 0 });
	}
}

int callJob(int cTime, int wID, int mNum, int mOpt)
{
	int ret = 0;
	jobs[wID].startedAt = cTime;
	if (mOpt == 0) {
		while (mNum) {
			Pair p = maxH.top();
			maxH.pop();

			Robot& r = robots[p.id];
			if (r.isBroken || r.job > 0 || r.iq != p.iq)
				continue;
			mNum--;
			r.job = wID;
			jobs[wID].robots.push_back(p.id);
			ret += p.id;
		}
	}
	else {
		while (mNum) {
			Pair p = minH.top();
			minH.pop();

			Robot& r = robots[p.id];
			if (r.isBroken || r.job > 0 || r.iq != p.iq)
				continue;
			mNum--;
			r.job = wID;
			jobs[wID].robots.push_back(p.id);
			ret += p.id;
		}
	}

	return ret;
}

void returnJob(int cTime, int wID)
{
	int diff = cTime - jobs[wID].startedAt;
	for (int rID : jobs[wID].robots) {
		Robot& r = robots[rID];
		if (r.job != wID)
			continue;
		r.job = 0;
		r.iq -= diff;

		maxH.push({ rID, r.iq });
		minH.push({ rID, r.iq });
	}
}

void broken(int cTime, int rID)
{
	Robot& r = robots[rID];
	if (r.isBroken || !r.job)
		return;
	r.isBroken = true;
	r.job = 0;
}

void repair(int cTime, int rID)
{
	Robot& r = robots[rID];
	if (!r.isBroken)
		return;
	r.iq = -cTime;
	r.job = 0;
	r.isBroken = false;

	maxH.push({ rID, r.iq });
	minH.push({ rID, r.iq });
}

int check(int cTime, int rID)
{
	Robot& r = robots[rID];
	if (r.isBroken)
		return 0;
	if (r.job)
		return -r.job;
	return r.iq + cTime;
}
