#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;
const int MDL = 1e9 + 7;

int n, m;
vector<int> adj[MAXN];
vector<int> topo;
int color[MAXN];
int f[MAXN];

void dfs(int u)
{
	color[u] = 1;
	for (auto v: adj[u])
	{
		if (!color[v])
			dfs(v);
	}
	color[u] = 2;
	topo.push_back(u);
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
	dfs(1);
	f[n] = 1;
	for (auto u: topo)
		for (auto v: adj[u])
			f[u] = (f[u] + f[v]) % MDL; 
	cout << f[1];
	return 0;
}