#include <iostream>
using namespace std;

const int MAXN = 1e6 + 2;

string S, T;
int kmp[MAXN];
int match[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> S;
	cin >> T;
	int n = S.size(), m = T.size();
	S = " " + S, T = " " + T;

	for (int i = 2; i <= m; i++)
	{
		int k = kmp[i - 1];
		while (k > 0 && T[k + 1] != T[i])
			k = kmp[k];
		if (T[k + 1] == T[i])
			kmp[i] = k + 1;
	}

	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		int k = match[i - 1];
		while (k > 0 && S[i] != T[k + 1])
			k = kmp[k];
		if (S[i] == T[k + 1])
			match[i] = k + 1;
		if (match[i] == m)
			++res;
	}

	cout << res;

	return 0;
}
