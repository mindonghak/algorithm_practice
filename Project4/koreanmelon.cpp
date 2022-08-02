#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, order[2][6], xmax = -1, ymax = -1, minarea=1, k;
	cin >> k;
	for (i = 0; i < 6; i++) {
		cin >> order[0][i] >> order[1][i];	//방향과 길이
		if (order[0][i] == 1 || order[0][i] == 2) {	//가로
			xmax = xmax < order[1][i] ? order[1][i] : xmax;	//최대길이가 긴 변
		}
		else {	//세로
			ymax = ymax < order[1][i] ? order[1][i] : ymax;
		}
	}
	for (i = 0; i < 6; i++) {
		if (!i&&order[0][5] == order[0][1]) {	//이전과 다음이 같은 방향이라면 꺾이는 지점(i==0)
			minarea *= order[1][0];	//가로와 세로 곱할거라 구분없이 미리 곱해버림
		}
		else if (i == 5 && order[0][4] == order[0][0]) {	//인덱스처리
			minarea *= order[1][5];
		}
		else if (order[0][i - 1] == order[0][i + 1]) {
			minarea *= order[1][i];
		}
	}
	cout << (xmax * ymax - minarea) * k;

	return 0;
}