#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;
const int MDL = 1e9 + 7;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];
int f[MAXN];

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	f[u] = 1;
	while (q.size())
	{
		u = q.front();
		q.pop();
		for (auto v: adj[u])
		{
			if (!visited[v])
			{
				visited[v] = 1;
				f[v] = (f[v] + f[u]) % MDL;
				q.push(v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i < n; i++)
	{
		adj[i].push_back(i + 1);
	}
	bfs(1);
	cout << f[n];
	return 0;
}