#include <iostream>
#include <vector>
using namespace std;

int t;
long long n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int gap = 1e3 + 2; //prime gap
		vector<bool> isPrime(gap, true);
		long long L = n + 1, R = L + gap - 1;
		for (long long i = 2; i * i <= R; i++)
			for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
				isPrime[j - L] = false;
		long long res = n + 1;
		while (!isPrime[res - L])
			++res;
		cout << res << "\n";
	}
	return 0;
}
