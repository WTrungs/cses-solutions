#include <iostream>
#include <stack>
using namespace std;

const int MAXN = 1e3 + 2;

int n, m;
int A[MAXN];
int B[MAXN];
int f[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	for (int i = 1; i <= m; i++)
		cin >> B[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (A[i] == B[j])
				f[i][j] = f[i - 1][j - 1] + 1;
			else
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
	cout << f[n][m] << "\n";
	int L = n, R = m;
	stack<int> st;
	while (L > 0 && R > 0)
	{
		if (A[L] == B[R])
		{
			st.push(A[L]);
			--L, --R;
		}
		else if (f[L - 1][R] == f[L][R])
			--L;
		else
			--R;
	}
	while (st.size())
	{
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}