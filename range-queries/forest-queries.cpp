#include <iostream>
using namespace std;

const int MAXN = 1e3 + 2;

int n, q;
char arr[MAXN][MAXN];
int preSum[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + (arr[i][j] == '*');
	for (int i = 1; i <= q; i++)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << preSum[y2][x2] - preSum[y2][x1 - 1] - preSum[y1 - 1][x2] + preSum[y1 - 1][x1 - 1] << "\n";
	}
	return 0;
}
