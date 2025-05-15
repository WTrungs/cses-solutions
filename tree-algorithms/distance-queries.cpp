#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 2;

int n, q;
vector<int> adj[MAXN];
int up[MAXN][20];
int depth[MAXN];

void dfs(int u, int par = 0)
{
	up[u][0] = par;
	for (int i = 1; i < 20; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (auto v: adj[u])
		if (v != par)
		{
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
}

int lca(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);
	int dist = depth[a] - depth[b];
	for (int i = 0; i < 20; i++)
		if ((dist >> i) & 1)
			a = up[a][i];
	if (a == b)
		return a;
	for (int i = 19; i >= 0; i--)
		if (up[a][i] && up[b][i] && up[a][i] != up[b][i])
		{
			a = up[a][i];
			b = up[b][i];
		}
	return up[a][0];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= q; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << depth[a] + depth[b] - 2 * depth[lca(a, b)] << "\n";
	}
	return 0;
}