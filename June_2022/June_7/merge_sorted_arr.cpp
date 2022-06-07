#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertAtindex(vector<int> &arr, int value, int index)
    {
        int n = arr.size();
        for (int i = n - 2; i >= index; --i)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        vector<int> res(m + n);
        int i = 0, j = 0, k = 0;
        while ((i < m) && (j < n))
        {
            if (nums1[i] < nums2[j])
                res[k] = nums1[i++];
            else
                res[k] = nums2[j++];
            k++;
        }
        while (i < m)
        {
            res[k] = nums1[i];
            i++;
            k++;
        }

        while (j < n)
        {
            res[k] = nums2[j];
            j++;
            k++;
        }
        nums1 = res;
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