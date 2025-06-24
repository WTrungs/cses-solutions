#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1e3 + 2;

template <class T>
struct FenwickTree2D
{
    vector<vector<T>> data;

    FenwickTree2D(int n, int m, T x)
    {
        data = vector<vector<T>>(n + 1, vector<T>(m + 1, x));
    }

    const int getRow() const
    {
        return data.size() - 1;
    }

    const int getCol() const
    {
        return data[0].size() - 1;
    }

    void process(T& x, T y) //update fen[id] by x
    {
        x += y;
    }

    void update(int x, int y, T val)
    {
        for (int i = x; i <= getRow(); i += i & -i)
            for (int j = y; j <= getCol(); j += j & -j)
                process(data[i][j], val);
    }

    T query(int x, int y)
    {
        T res = data[0][0];
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                process(res, data[i][j]);
        return res;
    }
};

int n, q;
int arr[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
    FenwickTree2D<int> fen(n, n, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            arr[i][j] = (ch == '*');
            fen.update(i, j, arr[i][j]);
        }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int y, x;
            cin >> y >> x;
            int change = (!arr[y][x]) - arr[y][x];
            arr[y][x] = !arr[y][x];
            fen.update(y, x, change);
        }
        else
        {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << fen.query(y2, x2) - fen.query(y2, x1 - 1) - fen.query(y1 - 1, x2) + fen.query(y1 - 1, x1 - 1) << "\n";
        }
    }
	return 0;
}
