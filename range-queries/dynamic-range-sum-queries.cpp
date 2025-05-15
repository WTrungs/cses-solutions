#include <iostream>
using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
int arr[MAXN];
long long fen[MAXN];

void update(int id, int x)
{
	while (id <= n)
	{
		fen[id] += x;
		id += id & -id;
	}
}

void build()
{
	for (int i = 1; i <= n; i++)
		update(i, arr[i]);
}

long long preSum(int id)
{
	long long res = 0;
	while (id)
	{
		res += fen[id];
		id -= id & -id;
	}
	return res;
}

long long query(int a, int b)
{
	return preSum(b) - preSum(a - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build();
	for (int i = 1; i <= q; i++)
	{
		int type, a, b;
		cin >> type >> a >> b;
		if (type == 1)
		{
			update(a, b - arr[a]);
			arr[a] = b;
		}
		else
		{
			cout << query(a, b) << "\n";
		}
	}
	return 0;
}

