#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 1e3 + 2;

struct Position
{
	int type;
	int x;
	int y;

	Position()
	{
		x = 0;
		y = 0;
		type = 0;
	}

	Position(int x, int y, int type = 0)
	{
		this->x = x;
		this->y = y;
		this->type = type;
	}

	friend Position operator - (Position a, Position b)
	{
		return Position(b.x - a.x, b.y - a.y);
	}

	friend bool operator < (Position a, Position b)
	{
		if (a.x != b.x)
			return a.x < b.x;
		return a.y < b.y;
	}
};

int n, m;
char arr[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool visited[MAXN][MAXN];
Position trace[MAXN][MAXN];
vector<Position> posList;
map<Position, char> direction;
vector<char> res;
bool beginOnBorder = false;

bool OnBorder(Position pos)
{
	return (pos.x == 1 || pos.x == n) || (pos.y == 1 || pos.y == m);
}

bool InMatrix(Position pos)
{
	return (1 <= pos.x && pos.x <= n) && (1 <= pos.y && pos.y <= m);
}

bool Visited(Position pos)
{
	return visited[pos.x][pos.y];
}

char Value(Position pos)
{
	return arr[pos.x][pos.y];
}

bool CanVisit(Position pos)
{
	return !Visited(pos) && Value(pos) == '.';
}

bool bfs()
{
	queue<Position> q;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 'M')
			{
				visited[i][j] = true;
				q.push(Position(i, j, 1));
			}
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 'A')
			{
				visited[i][j] = true;
				Position start(i, j, 2);
				if (OnBorder(start))
				{
					beginOnBorder = true;
					return true;
				}
				q.push(Position(start));
			}
		}

	while (q.size())
	{
		Position u = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Position newPos(u.x + dx[i], u.y + dy[i], u.type);
			if (CanVisit(newPos))
			{
				visited[newPos.x][newPos.y] = true;
				if (u.type == 2)
					trace[newPos.x][newPos.y] = u;
				q.push(newPos);
				if (newPos.type == 2 && OnBorder(newPos))
				{
					u = newPos;
					while (arr[u.x][u.y] != 'A')
					{
						posList.push_back(u);
						u = trace[u.x][u.y];
					}
					posList.push_back(u);
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	bool check = bfs();

	if (check)
	{
		cout << "YES\n";
		if (beginOnBorder)
		{
			cout << 0;
			return 0;
		}
		cout << posList.size() - 1 << "\n";
		direction[Position(-1, 0)] = 'U';
		direction[Position(1, 0)] = 'D';
		direction[Position(0, -1)] = 'L';
		direction[Position(0, 1)] = 'R';

		for (int i = 1; i < (int)posList.size(); i++)
		{
			res.push_back(direction[posList[i] - posList[i - 1]]);
		}

		reverse(res.begin(), res.end());

		for (auto ch: res)
			cout << ch;
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
