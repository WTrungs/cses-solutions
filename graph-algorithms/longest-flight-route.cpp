#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 2;

int n, m;
vector<int> adj[MAXN];
int maxV[MAXN];
bool visited[MAXN];
int trace[MAXN];

int dfs(int u)
{
	if (visited[u])
		return maxV[u];
	visited[u] = 1;
	for (auto v: adj[u])
	{
		if (!visited[v])
			maxV[v] = dfs(v);
		if (maxV[v] != 0)
		{
			if (maxV[u] < maxV[v] + 1)
			{
				maxV[u] = maxV[v] + 1;
				trace[u] = v;
			}
		}
	}
	return maxV[u];
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
	maxV[n] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
			dfs(i);
	}
	if (maxV[1] == 0)
		cout << "IMPOSSIBLE";
	else
	{
		cout << maxV[1] << "\n";
		int u = 1;
		while (true)
		{
			cout << u << " ";
			if (u == n)
				break;
			u = trace[u];
		}
	}
	return 0;
}
