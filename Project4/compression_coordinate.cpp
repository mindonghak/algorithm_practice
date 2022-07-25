#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
struct Num {
	int index;
	int x;
	int order;
};
Num num[1000000];
bool compare1(Num a, Num b) {
	return a.x < b.x;
}
bool compare2(Num a, Num b) {
	return a.index < b.index;
}
int main() {
	int n, i, y;
	cin >> n;
	for (i = 0; i < n; i++) {
		num[i].index = i;
		cin >> num[i].x;
	}
	sort(num, num + i, compare1);
	int order = 0;
	for (i = 0; i < n; i++) {
		if (i && num[i].x != num[i - 1].x)order++;
		num[i].order = order;
	}
	sort(num, num + i, compare2);
	for (i = 0; i < n; i++) {
		cout << num[i].order<<' ';
	}

	return 0;
}