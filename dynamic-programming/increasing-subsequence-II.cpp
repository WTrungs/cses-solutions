#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 2;
const int MDL = 1e9 + 7;

int n;
int arr[MAXN];
vector<int> sorted;
int f[MAXN];
int preSum[MAXN];
int fen[MAXN];

void update(int id, int x)
{
	while (id <= n)
	{
		fen[id] = (fen[id] + x) % MDL;
		id += (id & -id);
	}
}

int query(int id)
{
	int res = 0;
	while (id > 0)
	{
		res = (res + fen[id]) % MDL;
		id -= (id & -id);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
		sorted.push_back(arr[i]);
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
	for (int i = 1; i <= n; i++)
	{
		arr[i] = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = (query(arr[i] - 1) + 1) % MDL;
		update(arr[i], f[i]);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = (res + f[i]) % MDL;
	}
	cout << res;
	return 0;
}
