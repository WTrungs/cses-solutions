#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 2;

int n;
int x[MAXN];
int p[MAXN];
int b[MAXN];
int seg[4 * MAXN];

void Build(int id, int L, int R)
{
	if (L == R)
	{
		seg[id] = b[L];
		return;
	}
	int mid = (L + R) >> 1;
	Build(2 * id, L, mid);
	Build(2 * id + 1, mid + 1, R);
	seg[id] = seg[2 * id] + seg[2 * id + 1];
}

void Update(int id, int L, int R, int pos, int x)
{
	if (L == R)
	{
		if (L == pos)
			seg[id] = x;
		return;
	}
	if (R < pos || pos < L)
		return;
	int mid = (L + R) >> 1;
	Update(2 * id, L, mid, pos, x);
	Update(2 * id + 1, mid + 1, R, pos, x);
	seg[id] = seg[2 * id] + seg[2 * id + 1];
}

int Search(int pos)
{
	int store = 0;
	int id = 1, L = 1, R = n;
	while (L < R)
	{
		int mid = (L + R) >> 1;
		if (store + seg[2 * id] >= pos)
		{
			id = id * 2;
			R = mid;
		}
		else
		{
			store += seg[2 * id];
			id = 2 * id + 1;
			L = mid + 1;
		}
	}
	return L;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	fill(b + 1, b + n + 1, 1);
	Build(1, 1, n);
	for (int i = 1; i <= n; i++)
	{
		int id = Search(p[i]);
		cout << x[id] << " ";
		Update(1, 1, n, id, 0);
		b[id] = 0;
	}
	return 0;
}
