#include <iostream>
using namespace std;
int minimum;
int main() {
	int n, i, temp, Sum;
	cin >> n;
	int digit = (n / 10) + 1;
	for (i = n - 9 * digit; i < n; i++) {
		Sum = temp = i;
		while (temp) {
			Sum += temp % 10;
			temp /= 10;
		}
		if (Sum == n) {
			if (!minimum)minimum = i;
			else {
				if (i < minimum)minimum = i;
			}
		}
	}
	cout << minimum;
	return 0;
}