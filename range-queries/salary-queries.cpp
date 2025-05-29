#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Query
{
	char op;
	int a;
	int b;
};

int n, q;
vector<int> arr;
vector<int> distinct;
vector<Query> queries;
vector<int> fen;

int getID(int x)
{
	return lower_bound(distinct.begin(), distinct.end(), x) - distinct.begin() + 1;
}

void update(int id, int x)
{
	while (id <= (int)distinct.size())
	{
		fen[id] += x;
		id += (id & -id);
	}
}

int getSum(int id)
{
	int res = 0;
	while (id > 0)
	{
		res += fen[id];
		id -= (id & -id);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	arr = vector<int> (n + 2, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		distinct.push_back(arr[i]);
	}

	for (int i = 1; i <= q; i++)
	{
		Query x;
		cin >> x.op >> x.a >> x.b;
		if (x.op == '!')
			distinct.push_back(x.b);
		else
		{
			distinct.push_back(x.a);
			distinct.push_back(x.b);
		}
		queries.push_back(x);
	}

	sort(distinct.begin(), distinct.end());
	distinct.erase(unique(distinct.begin(), distinct.end()), distinct.end());
	fen = vector<int> (distinct.size() + 2, 0);

	for (int i = 1; i <= n; i++)
		update(getID(arr[i]), 1);

	for (auto query: queries)
	{
		if (query.op == '!')
		{
			int before = arr[query.a];
			int after = query.b;
			arr[query.a] = after;
			update(getID(before), -1);
			update(getID(after), 1);
		}
		else
		{
			cout << getSum(getID(query.b)) - getSum(getID(query.a) - 1) << "\n";
		}
	}

	return 0;
}
