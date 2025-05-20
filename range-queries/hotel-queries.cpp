#include <iostream>
using namespace std;

const int MAXN = 2e5 + 2;

int n, m;
int h[MAXN];
int r[MAXN];
int seg[4 * MAXN];

void Build(int id, int L, int R)
{
	if (L == R)
	{
		seg[id] = h[L];
		return;
	}
	int mid = (L + R) >> 1;
	Build(2 * id, L, mid);
	Build(2 * id + 1, mid + 1, R);
	seg[id] = max(seg[2 * id], seg[2 * id + 1]);
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
	seg[id] = max(seg[2 * id], seg[2 * id + 1]);
}

int Search(int id, int L, int R, int x)
{
	if (seg[id] < x)
		return -1;
	if (L == R)
		return L;
	int mid = (L + R) >> 1;
	int temp = Search(2 * id, L, mid, x);
	if (temp != -1)
		return temp;
	return Search(2 * id + 1, mid + 1, R, x);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= m; i++)
		cin >> r[i];
	Build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int temp = Search(1, 1, n, r[i]);
		if (temp == -1)
			cout << 0 << " ";
		else
		{
			Update(1, 1, n, temp, h[temp] - r[i]);
			h[temp] -= r[i];
			cout << temp << " ";
		}
	}
	return 0;
}
