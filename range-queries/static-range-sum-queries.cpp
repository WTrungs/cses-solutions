#include <iostream>
using namespace std;

const int MAXN = 2e5 + 2;

int n, q;
int arr[MAXN];
long long preSum[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
		preSum[i] = preSum[i - 1] + arr[i];
	for (int i = 1; i <= q; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << preSum[b] - preSum[a - 1] << "\n";
	}
	return 0;
}