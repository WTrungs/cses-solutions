#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
string addSpace = " ";
int n;
vector<int> f;

void init()
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		addSpace += ' ';
		addSpace += str[i];
	}
	addSpace += ' ';
	n = addSpace.size() - 1;
	str = ' ' + str;
	f = vector<int> (addSpace.size(), 0);
}

void manacher()
{
	int L = 1, R = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i > R)
			f[i] = 0;
		else
			f[i] = min(f[L + R - i], R - i);
		while (i - f[i] - 1 >= 1 && i + f[i] + 1 <= n && addSpace[i - f[i] - 1] == addSpace[i + f[i] + 1])
			++f[i];
		if (i + f[i] > R)
		{
			L = i - f[i];
			R = i + f[i];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	init();
	manacher();
	int res = 0, pos = -1;
	for (int i = 1; i <= n; i++)
		if (f[i] > res)
		{
			res = f[i];
			pos = i;
		}
	int R = res / 2;
	if (addSpace[pos] == ' ')
		for (int i = pos / 2 - R + 1; i <= pos / 2 + R; i++)
			cout << str[i];
	else
		for (int i = pos / 2 - R; i <= pos / 2 + R; i++)
			cout << str[i];
	return 0;
}

