#include <iostream>
using namespace std;

const int MAXN = 2e5 + 2;
const long long INF = 1e18;

int n, q;
int arr[MAXN];
long long lazy[4 * MAXN];

void down(int id)
{
	lazy[2 * id] += lazy[id];
	lazy[2 * id + 1] += lazy[id];
	lazy[id] = 0;
}

void update(int id, int L, int R, int a, int b, int val)
{
	if (a <= L && R <= b)
	{
		lazy[id] += val;
		return;
	}
	if (b < L || R < a)
		return;
	down(id);
	int mid = (L + R) >> 1;
	update(2 * id, L, mid, a, b, val);
	update(2 * id + 1, mid + 1, R, a, b, val);
}

long long query(int id, int L, int R, int k)
{
	if (R < k || k < L)
		return INF;
	if (L == R)
	{	if (L == k)
			return lazy[id];
		else
			return INF;
	}
	down(id);
	int mid = (L + R) >> 1;
	return min(query(2 * id, L, mid, k), query(2 * id + 1, mid + 1, R, k));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= q; i++)
	{
		int op, a, b, u, k;
		cin >> op;
		if (op == 1)
		{
			cin >> a >> b >> u;
			update(1, 1, n, a, b, u);
		}
		else
		{
			cin >> k;
			cout << arr[k] + query(1, 1, n, k) << "\n";
		}
	}
	return 0;
}

