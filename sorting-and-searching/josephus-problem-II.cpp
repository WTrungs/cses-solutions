#include <iostream>
using namespace std;

const int MAXN = 2e5 + 2;

int n, k;
int arr[MAXN];
int b[MAXN];
int seg[4 * MAXN];

int findPos(int pos)
{
	int preSum = 0;
	int id = 0, L = 0, R = n - 1;
	while (L < R)
	{
		int mid = (L + R) >> 1;
		if (preSum + seg[2 * id + 1] >= pos)
		{
			R = mid;
			id = 2 * id + 1;
		}
		else
		{
			L = mid + 1;
			preSum += seg[2 * id + 1];
			id = 2 * id + 2;
		}
	}
	return L;
}

void build(int id, int L, int R)
{
	if (L == R)
	{
		seg[id] = b[L];
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 1, L, mid);
	build(2 * id + 2, mid + 1, R);
	seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

void update(int id, int L, int R, int pos, int x)
{
	if (R < pos || pos < L)
		return;
	if (L == R)
	{
		seg[id] = x;
		return;
	}
	int mid = (L + R) >> 1;
	update(2 * id + 1, L, mid, pos, x);
	update(2 * id + 2, mid + 1, R, pos, x);
	seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
		b[i] = 1;
	}

	build(0, 0, n - 1);

	int curPos = 0;

	for (int i = n; i >= 1; i--)
	{
		curPos = (curPos + k) % i;
		int index = findPos(curPos + 1);
		cout << arr[index] << " ";
		update(0, 0, n - 1, index, 0);
		b[index] = 0;
	}

	return 0;
}
