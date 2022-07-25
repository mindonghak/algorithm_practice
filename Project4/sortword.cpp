#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
string word[20000];
bool compare(string a, string b) {
	if (a.length()==b.length())return a<b;
	return a.length() < b.length();
}
int main() {
	int n, i, y;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> word[i];
	}
	sort(word, word + n, compare);
	for (i = 0; i < n; i++) {
		if (i && !word[i].compare(word[i - 1]))continue;
		cout << word[i]<<'\n';
	}

	return 0;
}