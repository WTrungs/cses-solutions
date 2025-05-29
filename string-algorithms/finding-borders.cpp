#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 2;

string str;
int kmp[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	int n = str.size();
	str = " " + str;

	for (int i = 2; i <= n; i++)
	{
		int k = kmp[i - 1];
		while (k > 0 && str[i] != str[k + 1])
			k = kmp[k];
		if (str[i] == str[k + 1])
			kmp[i] = k + 1;
	}

	int k = kmp[n];
	vector<int> res;

	while (k > 0)
	{
		res.push_back(k);
		k = kmp[k];
	}

	reverse(res.begin(), res.end());

	for (auto x: res)
		cout << x << " ";

	return 0;
}
