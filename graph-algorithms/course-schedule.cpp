#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 2;

int n, m;
vector<int> adj[MAXN];
int color[MAXN];
vector<int> topo;

bool dfs(int u)
{
	color[u] = 1;
	for (auto v: adj[u]) 
	{
		if (!color[v])
		{
			if (!dfs(v))
				return false;
		}
		else if (color[v] == 1)
			return false;
	}
	color[u] = 2;
	topo.push_back(u);
	return true;
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
	bool check = true;
	for (int i = 1; i <= n; i++)
	{
		if (!color[i])
		{
			check = check && dfs(i);
		}
	}
	if (!check)
		cout << "IMPOSSIBLE";
	else
	{
		reverse(topo.begin(), topo.end());
		for (auto u: topo)
			cout << u << " ";
	}
	return 0;
}