#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class info {
	int _age;
	string _name;

public:
	info(int age, string name) : _age(age), _name(name) {};
	int age() { return _age; };
	const char* name() { return _name.c_str(); };
};

void merge_sort(vector<info>&, int start, int end);
void merge(vector<info>&, int start, int mid, int end);

int main() {
	vector<info> v;
	int n;
	cin >> n;

	int age; string name;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		v.emplace_back(age, name);
	}

	merge_sort(v, 0, n - 1);
	for (vector<info>::iterator iter = v.begin(); iter != v.end(); iter++)
		printf("%d %s\n", (*iter).age(), (*iter).name());

	return 0;
}

void merge_sort(vector<info>& v, int start, int end) {
	if (start < end)
	{
		int mid = (start + end) / 2;
		merge_sort(v, start, mid);
		merge_sort(v, mid + 1, end);

		merge(v, start, mid, end);
	}

}

void merge(vector<info>& v, int start, int mid, int end) {
	int left = start, right = mid + 1, buf_idx = start;
	vector<info> buffer;

	while (left <= mid && right <= end) {
		if (v[left].age() > v[right].age())
			buffer.push_back(v[right++]);
		else
			buffer.push_back(v[left++]);
	}

	while(left <= mid)
		buffer.push_back(v[left++]);
	while (right <= end)
		buffer.push_back(v[right++]);

	for (int i = start; i <= end; i++)
		v[i] = buffer[i - start];

	buffer.clear();
}