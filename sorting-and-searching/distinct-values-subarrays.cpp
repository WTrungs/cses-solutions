#include <iostream>
#include <set>
using namespace std;

const int MAXN = 2e5 + 2;

int n;
int arr[MAXN];
set<int> s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int L = 1, R = 0;
	long long res = 0;
	while (L <= n)
	{
		if (R < L)
			R = L;
		while (R <= n && s.find(arr[R]) == s.end())
		{
			s.insert(arr[R]);
			++R;
		}
		--R;
		int len = R - L + 1;
		res += len;
		s.erase(arr[L]);
		++L;
		++R;
	}
	cout << res;
	return 0;
}