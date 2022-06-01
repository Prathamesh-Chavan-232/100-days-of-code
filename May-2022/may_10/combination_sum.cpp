#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define pb push_back
#define mp make_pair
#define pqb priority_queue<int>
#define pqs priority_queue<int, vector<int>, greater<int>>
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define formap(m) for (auto [key, value] : m)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Typdefs for containers
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " =";
    string delim = " ";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

// STL vector / set (of any type) debugger
#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif
template <typename T>
void _print(T const &c)
{
    cerr << "{ ";
    foreach (it, c)
    {
        cerr << *it << ", ";
    }
    cerr << "}";
}

// Function definitions
void Add_edge(int v1, int v2);
void dfs(int vertex);

// constants
const int mod = 1'000'000'007;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

vpii graph[N]; // For Adjacency List
bool vis[N];

/*
    Link - https://leetcode.com/problems/combination-sum-iii/
    Problem - combination sum iii
    Difficulty - medium
    topic - back tracking
    Status - solved
    Date - 10/5/22 & 19/5/22
*/
/*  Approach 1 -

    Back tracking -


    we have to find all possible combinations of sum = n
    where i <= 9
    ∴           [1, 2, 3, 4, 5, 6, 7, 8, 9]


              _ _ _ _ _ _ _ [] _ _ _ _ _ _ _ _ _ _
            /   /   /   /   |   \   \   \   \     \
          [1] [2] [3] [4]  [5] [6] [7] [8] [9]    []
         /  \
        *    #
      /  \  / \
    ... (and so on)
    Depending on the value of k, the depth of the recursion tree will increase,
    here initially we have 10 choices (add anything from 1 - 9 or dont add anything (this is because we want to back track))

    After that each node of the tree will have 2 choices,
    * -> either add something, or #  /* -> dont add something (back track)
    Also we dont choose smaller numbers to avoid repetition

    e.g. k = 2, n = 3
              _ _ _ _ _ _ _ [] _ _ _ _ _ _ _ _ _ _
            /   /   /   /   |   \   \   \   \     \
          [1] [2] [3] [4]  [5] [6] [7] [8] [9]    []
         /  \  \                                 / \
      [1,2]   [1] (wont be pushed)                 []
(pushed)     /  \

Since this is brute force approach, all other incorrect choices will also be checked.
*/

/*  Approach 2 -

*/
class Solution
{
    vvi res;

public:
    void generate(vi &combination, int k, int n, int sum, int i)
    {
        if (k == 0)
        {
            if (sum == n)
            {
                res.pb(combination);
            }
            return;
        }
        if (i > 9)
            return;

        combination.pb(i);
        sum += i;

        generate(combination, k - 1, n, sum, i + 1);

        combination.pop_back();
        sum -= i;

        generate(combination, k, n, sum, i + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vi combination;
        int sum = 0;
        generate(combination, k, n, sum, 1);
        return res;
    }
};
void code()
{
    Solution s;
    int n, k;
    cin >> k >> n;
    vvi res = s.combinationSum3(k, n); // store return value
    debug(res.size());
    for (auto v : res)
    {
        debug(v.size());
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}
int main()
{
    // Start time
    auto start = chrono::steady_clock::now();

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// Input, Output & error messages inside text files
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    code();
// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}