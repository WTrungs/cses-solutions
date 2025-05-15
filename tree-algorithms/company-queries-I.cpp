#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 2;

int n, q;
vector<int> adj[MAXN];
int boss[MAXN];
int up[MAXN][20];

void dfs(int u, int par = 0)
{
	up[u][0] = par;
	for (int i = 1; i < 20; i++)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (auto v: adj[u])
		if (v != par)
			dfs(v, u);
}

int query(int x, int k)
{
	for (int i = 0; i < 20; i++)
		if ((k >> i) & 1)
			x = up[x][i];
	return (x == 0 ? -1 : x);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 2; i <= n; i++)
	{
		cin >> boss[i];
		adj[boss[i]].push_back(i);
		adj[i].push_back(boss[i]);
	}
	dfs(1);
	for (int i = 1; i <= q; i++)
	{
		int x, k;
		cin >> x >> k;
		cout << query(x, k) << "\n";
	}
	return 0;
}