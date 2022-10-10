#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int fish[100][100];
int fish2[100][100];
int N, K, Min;

void clear2();
void min_fish();
void jojul(int cur_col, int next_col, int row, int col);
void roll();
int _minmax();
int simul();
void print_fish(int mode);

int _count = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	int i;
	for (i = 0; i < N; i++) {
		cin >> fish[0][i];
	}
	//print_fish(1);
	while (simul() > K);
	//print_fish(1);

	cout << _count;

}

void min_fish() {
	queue <int> q;
	int i, _min = fish[0][0];
	q.push(0);
	for (i = 1; i < N; i++) {
		if (_min > fish[0][i]) {
			q = queue<int>();
			_min = fish[0][i];
			q.push(i);
		}
		else if (_min == fish[0][i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		fish[0][q.front()]++;
		q.pop();
	}
}
void clear2() {
	int i, j;
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			fish2[i][j] = 0;
		}
	}
}
void jojul(int cur_col, int next_col, int row, int col) {
	clear2();
	int d,i,j;
	
	for (i = 0; i < row; i++) {
		for (j = cur_col; j < next_col; j++) {
			d = 0;
			if (j + 1 != next_col) {
				if (fish[i][j] > fish[i][j + 1]) {
					d = (fish[i][j] - fish[i][j + 1]) / 5;
					if (d) {
						fish2[i][j] -= d;
						fish2[i][j + 1] += d;
					}
				}
				else if (fish[i][j] < fish[i][j + 1]) {
					d = (fish[i][j + 1] - fish[i][j]) / 5;
					if (d) {
						fish2[i][j + 1] -= d;
						fish2[i][j] += d;
					}
				}
			}
			if (i + 1 != row) {
				if (fish[i][j] > fish[i + 1][j]) {
					d = (fish[i][j] - fish[i + 1][j]) / 5;
					if (d) {
						fish2[i][j] -= d;
						fish2[i + 1][j] += d;
					}
				}
				else if (fish[i][j] < fish[i + 1][j]) {
					d = (fish[i + 1][j] - fish[i][j]) / 5;
					if (d) {
						fish2[i + 1][j] -= d;
						fish2[i][j] += d;
					}
				}
			}

		}
	}
}

void roll() {
	int i, j, row, col, cur_col, next_col;
	int r, c;
	cur_col = i = 0;
	row = col = 1;
	next_col = cur_col + 1;
	//print_fish(2);
	while (next_col+row-1<N) {
		for (c = 1; c <= col; c++) {
			for (r = next_col; r < next_col + row; r++) {
				fish[c][r] = fish[r - next_col][next_col - c];
			}
		}
		i % 2 == 0 ? row++ : col++;
		cur_col = next_col;
		next_col = cur_col + col;
		i++;

	}
	//print_fish(2);
	jojul(cur_col, next_col, row,col);
	int d;
	for (i = next_col; i < N; i++) {
		if (fish[0][i] > fish[0][i - 1]) {
			d = (fish[0][i] - fish[0][i - 1]) / 5;
			if (d) {
				fish2[0][i]-=d;
				fish2[0][i - 1]+=d;
			}
		}
		else if (fish[0][i] < fish[0][i - 1]) {
			d = (fish[0][i - 1] - fish[0][i]) / 5;
			if (d) {
				fish2[0][i - 1]-=d;
				fish2[0][i]+=d;
			}
		}
	}
	int k = 0;
	for (j = cur_col; j < next_col; j++) {
		for (i = 0; i < row; i++,k++) {
			fish[0][k] = fish[i][j] + fish2[i][j];
		}
	}
	for (i = next_col; i < N; i++) {
		fish[0][i] += fish2[0][i];
	}

	//print_fish(2);
}

void roll2() {
	int cur_col, row, col, i, j;
	cur_col = N / 2;
	row = 1;
	col = N / 2;
	for (i = cur_col, j = cur_col-1; i < N; i++,j--) {
		fish[1][i] = fish[0][j];
	}
	//print_fish(2);

	cur_col += N / 4;
	for (i = 0; i < 2; i++) {
		for (j = cur_col; j < N; j++) {
			fish[2 + i][j] = fish[1-i][cur_col * 2 - j - 1];
		}
	}
	//print_fish(2);
	int d;
	if (N == 4) {
		clear2();
		for (i = 0; i < 3; i++) {
			if (fish[i][cur_col] > fish[i + 1][cur_col]) {
				d = (fish[i][cur_col] - fish[i + 1][cur_col]) / 5;
				if (d) {
					fish2[i][cur_col] -= d;
					fish2[i + 1][cur_col] += d;
				}
			}
			else if (fish[i][cur_col] < fish[i + 1][cur_col]) {
				d = (fish[i + 1][cur_col] - fish[i][cur_col]) / 5;
				if (d) {
					fish2[i][cur_col] += d;
					fish2[i + 1][cur_col] -= d;
				}
			}
		}
	}
	else {
		jojul(cur_col, N, 4, N / 4);
	}
	for (i = 0; i < 4; i++) {
		for (j = cur_col; j < N; j++) {
			fish[i][j] += fish2[i][j];
		}
	}
	//print_fish(2);
	int k = 0;
	for (j = cur_col; j < N; j++) {
		for (i = 0; i < 4;i++, k++) {
			fish[0][k] = fish[i][j];
		}
	}
	//print_fish(1);
}
int _minmax() {
	int _min = 1000000;
	int _max = -1;
	int i = N;
	while (i--) {
		if (_min > fish[0][i]) {
			_min = fish[0][i];
		}
		if (_max < fish[0][i]) {
			_max = fish[0][i];
		}
	}
	return _max - _min;
}

int simul() {
	min_fish();
	roll();
	roll2();
	_count++;
	return _minmax();
}


void print_fish(int mode) {
	int i, j;
	switch (mode) {
		case 1:
			cout << "------------------\n";
			for (i = 0; i < N; i++) {
				printf("%d ", fish[0][i]);
			}
			cout << '\n';
			cout << "------------------\n";
			break;
		case 2:
			cout << "------------------\n";
			for (i = 0; i < 10; i++) {
				for (j = 0; j < 10; j++) {
					printf("%d ", fish[i][j]);
				}
				cout << '\n';
			}
			cout << "------------------\n";
			break;
	}
}