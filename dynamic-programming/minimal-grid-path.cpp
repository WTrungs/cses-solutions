#include <iostream>
#include <string>
using namespace std;

const int MAXN = 3e3 + 2;

int n;
char arr[MAXN][MAXN];
bool solved[MAXN][MAXN];
string f[MAXN][MAXN];

string findPath(int i, int j)
{
	if (solved[i][j])
		return f[i][j];
	solved[i][j] = 1;
	if (i == n && j == n)
	{
		return f[i][j] = string(1, arr[i][j]);
	}
	if (i == n)
	{
		return f[i][j] = arr[i][j] + findPath(i, j + 1);
	}
	if (j == n)
		return f[i][j] = arr[i][j] + findPath(i + 1, j);
	return f[i][j] = arr[i][j] + min(findPath(i + 1, j), findPath(i, j + 1));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	cout << findPath(1, 1);
	return 0;
}