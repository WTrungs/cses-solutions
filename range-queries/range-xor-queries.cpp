#include <iostream>
using namespace std;

const int MAXN = 2e5 + 2;

int n, q;
int arr[MAXN];
int xorSum[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		xorSum[i] = xorSum[i - 1] ^ arr[i];

	for (int i = 1; i <= q; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << (xorSum[b] ^ xorSum[a - 1]) << "\n";
	}
	return 0;
}

