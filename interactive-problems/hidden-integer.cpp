#include <iostream>
using namespace std;

int x;

string ask(int y)
{
	cout << "? " << y << endl;
	string res;
	cin >> res;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int L = 0, R = 1e9 + 1, res = -1;
	while (L <= R)
	{
		int mid = (L + R) >> 1;
		string query = ask(mid);
		if (query == "YES")
		{
			L = mid + 1;
		}
		else
		{
			res = mid;
			R = mid - 1;
		}
	}
	cout << "! " << res;
	return 0;
}