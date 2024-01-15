#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _coord{
	int row;
	int col;
} coord;

coord direction[4] = { {-1,0},{0,1},{1,0},{0,-1} };
int row_total, col_total;

//목표 좌표로부터 역으로 BFS를 수행한다
vector<vector<int>> BFS(vector<vector<int>>& maze, coord target);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row_total >> col_total;

	//미로 데이터 입력
	int i, j, value;
	vector<vector<int>> maze;
	coord target = { 0,0 };
	for (i = 0; i < row_total; i++) {
		vector<int> temp;
		maze.push_back(temp);
		for (j = 0; j < col_total; j++) {
			cin >> value;
			if (value == 2) {
				target.row = i;
				target.col = j;
			}
			maze[i].push_back(value);
		}
	}

	//목표 좌표에서 BFS 수행
	vector<vector<int>> distance = BFS(maze, target);

	//결과값 출력
	for (i = 0; i < row_total; i++)
		for (j = 0; j < col_total; j++)
			cout << distance[i][j] << (j == col_total - 1 ? '\n' : ' ');

}
vector<vector<int>> BFS(vector<vector<int>>& maze, coord target) {

	//방문 여부 저장할 visited, 거리 저장할 new_maze
	vector<vector<int>> visited(row_total, vector<int>(col_total, 0));

	queue<coord> Q;
	Q.push(target);
	visited[target.row][target.col] = 0;

	coord cur_pos;
	int dir, next_row, next_col;

	while (!Q.empty()) {
		cur_pos = Q.front();
		Q.pop();

		for (dir = 0; dir < 4; dir++) {
			next_row = cur_pos.row + direction[dir].row;
			next_col = cur_pos.col + direction[dir].col;

			if (next_row >= 0 && next_row < row_total && next_col >= 0 && next_col < col_total) {
				if (maze[next_row][next_col] == 1 && visited[next_row][next_col] == 0) {
					visited[next_row][next_col] = visited[cur_pos.row][cur_pos.col] + 1;
					Q.push({ next_row, next_col });
				}
			}
		}
	}

	for (int i = 0; i < row_total; i++) {
		for (int j = 0; j < col_total; j++) {
			if (maze[i][j] == 1 && visited[i][j] == 0)
				visited[i][j] = -1;
		}
	}

	return visited;
}