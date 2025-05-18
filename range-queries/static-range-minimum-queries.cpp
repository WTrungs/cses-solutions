#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 2;

int n, q;
int arr[MAXN];
int rmq[MAXN][20];
int LG[MAXN];

void Preprocess()
{
	for (int i = 2; i <= n; i++)
		LG[i] = LG[i / 2] + 1;
	for (int i = 1; i <= n; i++)
		rmq[i][0] = arr[i];
	for (int j = 1; j < 20; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
}

int GetMin(int a, int b)
{
	int k = LG[b - a + 1];
	return min(rmq[a][k], rmq[b - (1 << k) + 1][k]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	Preprocess();
	for (int i = 1; i <= q; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << GetMin(a, b) << "\n";
	}
	return 0;
}

