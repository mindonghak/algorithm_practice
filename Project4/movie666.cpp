#include <iostream>
using namespace std;

int digit[7];
int main() {
	int n,i,j;
	int result;
	cin >> n;

	if (n > 3700) {
		digit[0] = n / 3700;
		n %= 3700;

	}
	if (n > 280) {
		if (n < 1680) {
			digit[1] = n / 280;
			n %= 280;
			if (n < 114) {
				digit[2] = n / 19;
				n %= 19;
				if (n < 7) {
					digit[3] = n-1;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else if (n > 16) {
					digit[3] = n - 10;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else {
					digit[3] = digit[4] = digit[5] = 6;
					digit[6] = n - 7;
				}
			}
			else if (n > 223) {
				digit[2] = (n - 109) / 19 + 1;
				n -= 223;
				n %= 19;
				if (n < 7) {
					digit[3] = n - 1;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else if (n > 16) {
					digit[3] = n - 10;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else {
					digit[3] = digit[4] = digit[5] = 6;
					digit[6] = n - 7;
				}
			}
			else {
				digit[2] = 6;
				n -= 114;
				if (n < 7) {
					digit[3] = n-1;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else if (n > 106) {
					digit[3] = n - 100;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else {
					n -= 7;
					digit[4] = digit[3] = 6;
					digit[6] = n % 10;
					n /= 10;
					digit[5] = n % 10;
				}
			}
		}
		else if (n > 2860) {
			digit[1] = (n - 1180) / 280 + 1;
			n -= 2860;
			n %= 280;
			if (n < 114) {
				digit[2] = n / 19;
				n %= 19;
				if (n < 7) {
					digit[3] = n - 1;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else if (n > 16) {
					digit[3] = n - 10;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else {
					digit[3] = digit[4] = digit[5] = 6;
					digit[6] = n - 7;
				}
			}
			else if (n > 223) {
				digit[2] = (n - 109) / 19 + 1;
				n -= 223;
				n %= 19;
				if (n < 7) {
					digit[3] = n - 1;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else if (n > 16) {
					digit[3] = n - 10;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else {
					digit[3] = digit[4] = digit[5] = 6;
					digit[6] = n - 7;
				}
			}
			else {
				digit[2] = 6;
				n -= 114;
				if (n < 7) {
					digit[3] = n-1;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else if (n > 1006) {
					digit[3] = n - 1000;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else {
					n -= 7;
					digit[4] = digit[3] = 6;
					digit[6] = n % 10;
					n /= 10;
					digit[5] = n % 10;
				}
			}
		}
		else {
			digit[1] = 6;
			n -= 1680;
			if (n < 114) {
				digit[2] = n / 19;
				n %= 19;
				if (n < 7) {
					digit[3] = n - 1;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else if (n > 16) {
					digit[3] = n - 10;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else {
					digit[3] = digit[4] = digit[5] = 6;
					digit[6] = n - 7;
				}
			}
			else if (n > 1123) {
				digit[2] = (n - 1009) / 19 + 1;
				n -= 1123;
				n %= 19;
				if (n < 7) {
					digit[3] = n - 1;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else if (n > 16) {
					digit[3] = n - 10;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else {
					digit[3] = digit[4] = digit[5] = 6;
					digit[6] = n - 7;
				}
			}
			else {
				digit[2] = 6;
				n -= 114;
				if (n < 10) {
					digit[3] = n-1;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else if (n > 1006) {
					digit[3] = n-1000;
					digit[4] = digit[5] = digit[6] = 6;
				}
				else {
					n -= 7;
					digit[3] = 6;
					digit[6] = n % 10;
					n /= 10;
					digit[5] = n % 10;
					n /= 10;
					digit[4] = n % 10;
				}
			}
		}
	}
	else {
		if (n < 114) {
			digit[2] = n / 19;
			n %= 19;
			if (n < 7) {
				digit[3] = n - 1;
				digit[4] = digit[5] = digit[6] = 6;
			}
			else if (n > 16) {
				digit[3] = n - 10;
				digit[4] = digit[5] = digit[6] = 6;
			}
			else {
				digit[3] = digit[4] = digit[5] = 6;
				digit[6] = n - 7;
			}
		}
		else if (n > 223) {
			digit[2] = (n - 109) / 19 + 1;
			n -= 223;
			n %= 19;
			if (n < 7) {
				digit[3] = n - 1;
				digit[4] = digit[5] = digit[6] = 6;
			}
			else if (n > 16) {
				digit[3] = n - 10;
				digit[4] = digit[5] = digit[6] = 6;
			}
			else {
				digit[3] = digit[4] = digit[5] = 6;
				digit[6] = n - 7;
			}
		}
		else {
			digit[2] = 6;
			n -= 114;
			if (n < 7) {
				digit[3] = n-1;
				digit[4] = digit[5] = digit[6] = 6;
			}
			else if (n > 106) {
				digit[3] = n - 100;
				digit[4] = digit[5] = digit[6] = 6;
			}
			else {
				n -= 7;
				digit[4] = digit[3] = 6;
				digit[6] = n % 10;
				n /= 10;
				digit[5] = n % 10;
			}
		}
	}
	result = 0;
	for (i = 0; i < 7; i++) {
		result += digit[i];
		result *= 10;
	}
	result /= 10;
	cout <<result << '\n';
	
	return 0;
}