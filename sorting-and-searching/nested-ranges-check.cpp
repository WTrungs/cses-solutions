#include <iostream>
#include <algorithm>
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
int minRight[MAXN];
int maxRight[MAXN];
bool contained[MAXN];
bool isContained[MAXN];

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

	minRight[0] = INF;
	maxRight[n + 1] = -INF;

	for (int i = 1; i <= n; i++)
	{
		contained[arr[i].pos] = (minRight[i - 1] <= arr[i].right);
		minRight[i] = min(minRight[i - 1], arr[i].right);
	}

	for (int i = n; i >= 1; i--)
	{
		isContained[arr[i].pos] = (maxRight[i + 1] >= arr[i].right);
		maxRight[i] = max(maxRight[i + 1], arr[i].right);
	}

	for (int i = 1; i <= n; i++)
		cout << contained[i] << " ";

	cout << "\n";

	for (int i = 1; i <= n; i++)
		cout << isContained[i] << " ";

	return 0;
}
