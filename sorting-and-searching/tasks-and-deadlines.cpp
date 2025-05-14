#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 2;

struct Data
{
	int a;
	int d;
};

int n;
Data arr[MAXN];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].a >> arr[i].d;
	}
	sort(arr + 1, arr + n + 1, [&] (const Data& a, const Data& b)
	{
		if (a.a != b.a)
			return a.a < b.a;
		return a.d > b.d;
	}
	);
	long long cur = 0, res = 0;
	for (int i = 1; i <= n; i++)
	{
		cur += arr[i].a;
		res += arr[i].d - cur;
	}
	cout << res;
	return 0;
}