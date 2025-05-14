#include <iostream>
using namespace std;

const int MAXN = 1e2 + 2;

int n;
bool row[MAXN][2 * MAXN];
bool col[MAXN][2 * MAXN];
int arr[MAXN][MAXN];

int findMex(int i, int j)
{
	for (int mex = 0; mex <= 2 * n + 2; mex++)
		if (!row[i][mex] && !col[j][mex])
		{
			row[i][mex] = col[j][mex] = 1;
			return mex;
		}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{	
			arr[i][j] = findMex(i, j);
			row[i][arr[i][j]] = 1;
			col[j][arr[i][j]] = 1;
		}
	for (int i = 1; i <= n; i++) 
	{	
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return 0;
}