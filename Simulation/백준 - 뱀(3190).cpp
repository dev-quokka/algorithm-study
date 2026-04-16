// 백준 - 뱀(3190)
// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct MoveInfo {
	int x;
	char c;
};

struct SnakePos {
	int y, x;
};

int n, k, l;
int board[101][101] = { 0 }; // 뱀 몸통 = 1, 사과 = 2

deque<SnakePos> d;

int Simul(queue<MoveInfo>& q, int curx, int cury) {
	const int movex[4] = { 1, 0 ,-1, 0 };
	const int movey[4] = { 0, 1, 0, -1 };

	int curDir = 0, curTime = 0; // 현재 방향, 누적 시간

	while (true) {
		++curTime;

		curx += movex[curDir];
		cury += movey[curDir];

		if (curx <= 0 || curx > n
			|| cury <= 0 || cury > n || board[cury][curx] == 1) return curTime;

		// 움직인 위치에 사과 없을때
		// 사과 있으면 제거처리 안해줘도 됌
		if (board[cury][curx] == 0) {
			auto [ty, tx] = d.front();
			d.pop_front();
			board[ty][tx] = 0; // 뱀 꼬리 보드에서 제거
		}

		if (!q.empty() && q.front().x == curTime) {
			char tc = q.front().c; q.pop();

			if (tc == 'D') { // 오른쪽 90도 회전
				curDir = (curDir == 3 ? 0 : curDir + 1);
			}
			else { // 왼쪽 90도 회전
				curDir = (curDir == 0 ? 3 : curDir - 1);
			}
		}
        
        d.push_back({ cury , curx });
        board[cury][curx] = 1;
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < k; i++) { // 사과 위치
		int y, x; cin >> y >> x;
		board[y][x] = 2;
	}

	cin >> l;

	queue<MoveInfo> q;
	for (int i = 0; i < l; i++) { // 이동 정보
		int x; char c; cin >> x >> c;
		q.push({ x,c });
	}

	// 뱀 세팅
	board[1][1] = 1;
	d.push_back({ 1,1 });

	cout << Simul(q, 1, 1);
	return 0;
}