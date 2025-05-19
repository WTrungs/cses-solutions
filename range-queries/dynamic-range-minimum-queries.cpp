#include <iostream>
using namespace std;

const int MAXN = 2e5 + 2;
const int INF = 2e9;

int n, q;
int arr[MAXN];
int seg[4 * MAXN];

void build(int id, int L, int R)
{
	if (L == R)
	{
		seg[id] = arr[L];
		return;
	}

	int mid = (L + R) >> 1;
	build(2 * id, L, mid);
	build(2 * id + 1, mid + 1, R);
	seg[id] = min(seg[2 * id], seg[2 * id + 1]);
}

void update(int id, int L, int R, int pos, int x)
{
	if (L == pos && pos == R)
	{
		seg[id] = x;
		return;
	}

	if (pos < L || R < pos)
	{
		return;
	}

	int mid = (L + R) >> 1;
	update(2 * id, L, mid, pos, x);
	update(2 * id + 1, mid + 1, R, pos, x);
	seg[id] = min(seg[2 * id], seg[2 * id + 1]);
}

int query(int id, int L, int R, int a, int b)
{
	if (a <= L && R <= b)
		return seg[id];
	
	if (b < L || R < a)
		return INF;
	
	int mid = (L + R) >> 1;
	return min(query(2 * id, L, mid, a, b), query(2 * id + 1, mid + 1, R, a, b));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);

	for (int i = 1; i <= q; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 1)
		{
			arr[a] = b;
			update(1, 1, n, a, b);
		}
		else
		{
			cout << query(1, 1, n, a, b) << "\n";
		}
	}
	return 0;
}
