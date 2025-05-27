#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAXN = 3e3 + 2;

struct Point
{
	int x, y;

	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
};

int n;
char arr[MAXN][MAXN];
bool solved[MAXN][MAXN];
Point f[MAXN][MAXN];
queue<Point> q;

void bfs()
{
	Point finish = {n};
	q.push({1, 1});
	visited[1][1] = true;
	while (q.size())
	{
		Point u = q.front();
		q.pop();

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	bfs();
	return 0;
}
