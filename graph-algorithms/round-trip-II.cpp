#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 2;

int n, m;
vector<int> adj[MAXN];
int color[MAXN];
int trace[MAXN];
int start, finish;
vector<int> print;

bool findCycle(int u)
{
	color[u] = 1;
	for (auto v: adj[u])
	{
		if (!color[v])
		{
			trace[v] = u;
			if (findCycle(v))
				return true;
		}
		else if (color[v] == 1)
		{
			start = v;
			finish = u;
			return true;
		}
	}
	color[u] = 2;
	return 0;
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
	bool res = false;
	for (int i = 1; i <= n; i++)
	{
		if (!color[i])
		{
			res = res || findCycle(i);
		}
	}
	if (res)
	{
		print.push_back(start);
		while (finish != start)
		{
			print.push_back(finish);
			finish = trace[finish];
		}
		print.push_back(start);
		reverse(print.begin(), print.end());
		cout << print.size() << "\n";
		for (auto x: print)
			cout << x << " ";
	}
	else
		cout << "IMPOSSIBLE";
	return 0;
}

