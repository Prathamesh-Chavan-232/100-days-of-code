#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        vector<bool> col(n, true);
        vector<bool> anti(2 * n - 1, true);
        vector<bool> main(2 * n - 1, true);
        vector<int> row(n, 0);
        int count = 0;
        dfs(0, row, col, main, anti, count);
        return count;
    }
    void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool> &main, vector<bool> &anti, int &count)
    {
        if (i == row.size())
        {
            count++;
            return;
        }
        for (int j = 0; j < col.size(); j++)
        {
            if (col[j] && main[i + j] && anti[i + col.size() - 1 - j])
            {
                row[i] = j;
                col[j] = main[i + j] = anti[i + col.size() - 1 - j] = false;
                dfs(i + 1, row, col, main, anti, count);
                col[j] = main[i + j] = anti[i + col.size() - 1 - j] = true;
            }
        }
    }
};
void solve()
{
}
int main()
{
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}