#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
struct Info {
	int index;
	int age;
	string name;
};
Info info[100000];
bool compare(Info a, Info b) {
	if (a.age == b.age)return a.index < b.index;
	return a.age < b.age;
}
int main() {
	int n, i, y;
	cin >> n;
	for (i = 0; i < n; i++) {
		info[i].index = i;
		cin >> info[i].age >> info[i].name;
	}
	sort(info, info+n, compare);
	for (i = 0; i < n; i++) {
		cout << info[i].age<<' '<<info[i].name << '\n';
	}

	return 0;
}