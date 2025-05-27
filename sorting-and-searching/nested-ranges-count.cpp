#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 2;
const int INF = 2e9;

struct Segment
{
	int left;
	int right;
	int pos;

	Segment() : left(0), right(0) {}
};

int n;
Segment arr[MAXN];
vector<int> distinct;
int contains[MAXN];
int isContained[MAXN];
int fen[MAXN];

int getID(int x)
{
	return lower_bound(distinct.begin(), distinct.end(), x) - distinct.begin() + 1;
}

void update(int id, int x)
{
	while (id <= n)
	{
		fen[id] += x;
		id += (id & -id);
	}
}

int query(int id)
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

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].left >> arr[i].right;
		arr[i].pos = i;
	}

	sort(arr + 1, arr + n + 1, [&] (Segment a, Segment b)
	{
		if (a.left != b.left)
			return a.left > b.left;
		if (a.right != b.right)
			return a.right < b.right;
		return a.pos < b.pos;
	});

	for (int i = 1; i <= n; i++)
		distinct.push_back(arr[i].right);

	sort(distinct.begin(), distinct.end());
	distinct.erase(unique(distinct.begin(), distinct.end()), distinct.end());
	fill(fen, fen + n + 2, 0);

	for (int i = 1; i <= n; i++)
	{
		int id = getID(arr[i].right);
		contains[arr[i].pos] = query(id);
		update(id, 1);
	}

	fill(fen, fen + n + 2, 0);
	distinct.clear();

	for (int i = 1; i <= n; i++)
	{
		distinct.push_back(arr[i].left);
	}

	sort(distinct.begin(), distinct.end());
	distinct.erase(unique(distinct.begin(), distinct.end()), distinct.end());

	sort(arr + 1, arr + n + 1, [&] (Segment a, Segment b)
	{
		if (a.right != b.right)
			return a.right > b.right;
		if (a.left != b.left)
			return a.left < b.left;
		return a.pos < b.pos;
	});

	for (int i = 1; i <= n; i++)
	{
		int id = getID(arr[i].left);
		isContained[arr[i].pos] = query(id);
		update(id, 1);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << contains[i] << " ";
	}

	cout << "\n";

	for (int i = 1; i <= n; i++)
	{
		cout << isContained[i] << " ";
	}

	return 0;
}
