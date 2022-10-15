#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int R, C, K, W[2];
bool wall[30][30][2];
int map[25][25];
struct op {
	int x;
	int y;
	int dir;
};
struct op onpung[410];
int onpung_num, check_temp_num;
pair <int, int> check_temp[410];
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

void print_map();
void all_wind();
void wind(struct op cur_op, int level, int _check[25][25]);
int check_move(pair <int, int> p, int dir);
void regulate();
void release();
int check_result();
int main() {
	int result = 0;
	int i, j, temp, _wall, _x, _y, _dir;
	cin >> R >> C >> K;
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			cin >> temp;
			if (!temp)continue;
			else if (temp == 5) {
				check_temp_num++;
				check_temp[check_temp_num] = make_pair(i, j);
			}
			else {
				onpung_num++;
				onpung[onpung_num].x = i+dx[temp];
				onpung[onpung_num].y = j + dy[temp];
				onpung[onpung_num].dir = temp;
			}
		}
	}
	cin >> _wall;
	for (i = 1; i <= _wall; i++) {
		cin >> _x >> _y >> _dir;
		wall[_x][_y][_dir] = 1;
	}

	while (check_result()) {
		all_wind();
		regulate();
		release();
		result++;
		if (result > 100)break;
	}
		//print_map();
	cout << result;

	return 0;
}

int check_result() {
	int i;
	for (i = 1; i <= check_temp_num; i++) {
		if (map[check_temp[i].first][check_temp[i].second] < K)return 1;
	}
	return 0;
}

void release() {
	int i, j;
	for (i = 1; i <= R; i++) {
		if (map[i][1])map[i][1]--;
		if (map[i][C])map[i][C]--;
	}
	for (j = 2; j < C; j++) {
		if (map[1][j])map[1][j]--;
		if (map[R][j])map[R][j]--;
	}
}

void regulate() {
	int change[25][25];
	memset(change, 0, sizeof(change));
	int i, j;
	for (i = 1; i < R; i++) {
		for (j = 1; j < C; j++) {
			if (map[i][j] - map[i][j + 1] > 3 && !check_move(make_pair(i,j),1)) {
				change[i][j] -= (map[i][j] - map[i][j + 1]) / 4;
				change[i][j + 1] += (map[i][j] - map[i][j + 1]) / 4;
			}
			else if (map[i][j + 1] - map[i][j] > 3 && !check_move(make_pair(i, j), 1)) {
				change[i][j] += (map[i][j + 1] - map[i][j]) / 4;
				change[i][j + 1] -= (map[i][j + 1] - map[i][j]) / 4;
			}
			if (map[i][j] - map[i + 1][j] > 3 && !check_move(make_pair(i, j), 4)) {
				change[i][j] -= (map[i][j] - map[i + 1][j]) / 4;
				change[i + 1][j] += (map[i][j] - map[i + 1][j]) / 4;
			}
			else if (map[i + 1][j] - map[i][j] > 3 && !check_move(make_pair(i, j), 4)) {
				change[i][j] += (map[i + 1][j] - map[i][j]) / 4;
				change[i + 1][j] -= (map[i + 1][j] - map[i][j]) / 4;
			}
		}
	}
	for (i = 1; i < R; i++) {
		j = C;
		if (map[i][j] - map[i + 1][j] > 3 && !check_move(make_pair(i, j), 4)) {
			change[i][j] -= (map[i][j] - map[i + 1][j]) / 4;
			change[i + 1][j] += (map[i][j] - map[i + 1][j]) / 4;
		}
		else if (map[i + 1][j] - map[i][j] > 3 && !check_move(make_pair(i, j), 4)) {
			change[i][j] += (map[i + 1][j] - map[i][j]) / 4;
			change[i + 1][j] -= (map[i + 1][j] - map[i][j]) / 4;
		}
	}
	for (j = 1; j < C; j++) {
		i = R;
		if (map[i][j] - map[i][j + 1] > 3 && !check_move(make_pair(i, j), 1)) {
			change[i][j] -= (map[i][j] - map[i][j + 1]) / 4;
			change[i][j + 1] += (map[i][j] - map[i][j + 1]) / 4;
		}
		else if (map[i][j + 1] - map[i][j] > 3 && !check_move(make_pair(i, j), 1)) {
			change[i][j] += (map[i][j + 1] - map[i][j]) / 4;
			change[i][j + 1] -= (map[i][j + 1] - map[i][j]) / 4;
		}
	}
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			map[i][j] += change[i][j];
		}
	}
}

void all_wind() {
	for (int i = 1; i <= onpung_num; i++) {
		int _check[25][25];
		memset(_check, 0, sizeof(_check));
		wind(onpung[i], 5,_check);
	}
}

void wind(struct op cur_op, int level, int _check[25][25]) {
	if (!level)return;
	struct op n_op;
	int _x = cur_op.x;
	int _y = cur_op.y;
	if (_check[_x][_y])return;
	int _dir = cur_op.dir;
	int side_dir[2];
	side_dir[0] = _dir == 1 || _dir == 2 ? 3 : 1;
	side_dir[1] = _dir == 1 || _dir == 2 ? 4 : 2;
	map[_x][_y] += level;	//my position temp ++
	_check[_x][_y] = 1;
	n_op.dir = _dir;
	if (!check_move(make_pair(_x, _y), _dir)) {
		n_op.x = _x + dx[_dir];
		n_op.y = _y + dy[_dir];
		wind(n_op, level - 1, _check);
	}
	for (int i = 0; i < 2;i++) {
		if (check_move(make_pair(_x, _y), side_dir[i])|| check_move(make_pair(_x+dx[side_dir[i]], _y+dy[side_dir[i]]), _dir))
			continue;
		n_op.x = _x + dx[side_dir[i]] + dx[_dir];
		n_op.y = _y + dy[side_dir[i]] + dy[_dir];
		wind(n_op, level - 1,_check);
	}
}

int check_move(pair <int, int> p, int dir) {	//1 no way
	int _x = p.first;
	int _y = p.second;
	int n_x = _x + dx[dir];
	int n_y = _y + dy[dir];
	if (dir == 1) {
		if (wall[_x][_y][1]||n_y>C)
			return 1;
	}
	else if (dir == 2) {
		if (wall[_x][n_y][1] || n_y < 1)
			return 1;
	}
	else if (dir == 3) {
		if (wall[_x][_y][0] || n_x < 1)
			return 1;
	}
	else if (dir == 4) {
		if (wall[n_x][_y][0] || n_x > R)
			return 1;
	}
	return 0;
}

void print_map() {
	//for (int i = 1; i <= onpung_num; i++) {
	//	cout << onpung[i].x << ' ' << onpung[i].y << ' ' << onpung[i].dir << ' ';
	//}
	//cout << '\n';
	//for (int i = 1; i <= check_temp_num; i++) {
	//	cout << check_temp[i].first << ' ' << check_temp[i].second << ' ';
	//}
	//cout << '\n';
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	//for (int i = 1; i <= R; i++) {
	//	for (int j = 1; j <= C; j++) {
	//		cout << wall[i][j][0] << ' ';
	//	}
	//	cout << '\n';
	//}
	//for (int i = 1; i <= R; i++) {
	//	for (int j = 1; j <= C; j++) {
	//		cout << wall[i][j][1] << ' ';
	//	}
	//	cout << '\n';
	//}
}