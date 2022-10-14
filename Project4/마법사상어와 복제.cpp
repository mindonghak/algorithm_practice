#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int M, S;
int map[5][5][8];
int total[5][5];
int dup[5][5][8];
int red[5][5][150];
int _red = 1;
int shark[2];
int dir_y[9] = {0, -1,-1,0,1,1,1,0,-1 };
int dir_x[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int sd_x[5] = { 0, -1,0,1,0 };
int sd_y[5] = { 0, 0,-1,0,1 };
int rem_dir[3];

void print_map();
void move_fish();
int check_shark(int x, int y, int dir);
void shark_move();
void myf();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int i;
	cin >> M >> S;
	i = M;
	int temp[3];
	while (i--) {
		cin >> temp[0] >> temp[1] >> temp[2];
		map[temp[0]][temp[1]][temp[2]]++;
		total[temp[0]][temp[1]]++;
	}
	cin >> shark[0] >> shark[1];

	//print_map();

	while (S--) {
		myf();
	}
	int _result = 0;
	for (i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			for (int k = 1; k < 9; k++) {
				_result += map[i][j][k];
			}
		}
	}
	cout << _result;
	return 0;
}


void move_fish() {
	int noway[7][7];
	int i, j, d, k, out;
	for (i = 0; i < 6; i++) {
		noway[0][i] = -1;
	}
	for (i = 0; i < 6; i++) {
		noway[5][i] = -1;
	}
	for (i = 0; i < 6; i++) {
		noway[i][0] = -1;
	}
	for (i = 0; i < 6; i++) {
		noway[i][5] = -1;
	}
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			if (red[i][j][_red]||(shark[0]==i&&shark[1]==j)|| red[i][j][_red-1])noway[i][j] = -1;
		}
	}
	memset(dup, 0, sizeof(dup));
	memset(total, 0, sizeof(total));
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			for (d = 1; d < 9; d++) {
				if (!map[i][j][d])continue;
				k = d;
				out = 0;
				while (k) {
					if (out == 8) {
						dup[i][j][d] += map[i][j][d];
						total[i][j] += map[i][j][d];
						break;
					}
					if(noway[i+dir_x[k]][j+dir_y[k]]!=-1){
						//printf("i,j,k=%d %d %d\n", i, j, k);
						dup[i + dir_x[k]][j + dir_y[k]][k] += map[i][j][d];
						total[i + dir_x[k]][j + dir_y[k]] += map[i][j][d];
						break;
					}
					k--;
					if (k == 0)k += 8;
					out++;
				}
			}
		}
	}

}

int check_shark(int x, int y, int dir) {
	int dx = sd_x[dir];
	int dy = sd_y[dir];
	if (dx < 0 && x + dx < 1)return 0;
	else if (dx > 0 && x + dx > 4)return 0;
	if (dy < 0 && y + dy < 1)return 0;
	else if (dy > 0 && y + dy > 4)return 0;
	return 1;
}

void shark_move() {
	int i, j, k;
	int _sum[4] = {0,};
	int _max = -10000000;
	int x[4], y[4];
	x[0] = shark[0];
	y[0] = shark[1];
	for (i = 1; i < 5; i++) {
		if (!check_shark(x[0], y[0], i)) continue;
		x[1] = shark[0] + sd_x[i];
		y[1] = shark[1] + sd_y[i];
		_sum[0] = total[x[1]][y[1]];
		for (j = 1; j < 5; j++) {
			if (!check_shark(x[1], y[1], j)) continue;
			x[2] = x[1] + sd_x[j];
			y[2] = y[1] + sd_y[j];
			if (x[2] == x[0] && y[2] == y[0])_sum[1] = _sum[0];
			else _sum[1] = _sum[0] + total[x[2]][y[2]];
			for (k = 1; k < 5; k++) {
				if (!check_shark(x[2], y[2], k)) continue;
				x[3] = x[2] + sd_x[k];
				y[3] = y[2] + sd_y[k];
				if (x[3] != x[1] || y[3] != y[1]) {
					_sum[2] = _sum[1] + total[x[3]][y[3]];
				}
				else _sum[2] = _sum[1];
				if (_max < _sum[2]) {
					_max = _sum[2];
					rem_dir[0] = i;
					rem_dir[1] = j;
					rem_dir[2] = k;
				}
			}
		}
	}

}

void myf() {
	move_fish();
	//print_map();
	shark_move();
	_red++;

	for (int i = 0; i < 3; i++) {
		shark[0] += sd_x[rem_dir[i]];
		shark[1] += sd_y[rem_dir[i]];
		if (total[shark[0]][shark[1]]) {
			red[shark[0]][shark[1]][_red] = 1;
			for (int j = 1; j < 9; j++) {
				dup[shark[0]][shark[1]][j] = 0;
			}
			total[shark[0]][shark[1]] = 0;
		}
	//printf("%d %d:shark\n", shark[0], shark[1]);
	}
	//print_map();
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			for (int k = 1; k < 9; k++) {
				total[i][j] += map[i][j][k];
				map[i][j][k] += dup[i][j][k];
			}
		}
	}
	//print_map();
}

void print_map() {
	int i, j;
	cout << "------------" << '\n';
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			printf("%d ",total[i][j]);
		}
		cout << '\n';
	}
	cout << "-------------" << '\n';
}