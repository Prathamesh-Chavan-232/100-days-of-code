
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
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> ml;
typedef set<ll> sl;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_set<ll> usl;

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

// Varadiac I/O
template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}
template <typename... T>
void write(T &&...args)
{
    ((cout << args << " "), ...);
    cout << "\n";
}

// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;
vi graph[N]; // For Adjacency List

/*
    Link - https://leetcode.com/problems/132-pattern/
    Problem - 132 Pattern
    Difficulty - Medium
    contest - No (daily challenge May 2022)
    Status - solved
    Date - 7/5/22
*/
/*  Approach -

    O(n) Approach - Using monotonous Decreasing stack

    1) We need to keep track of the minimum element occuring before nums[k]
    2) We append every element to the stack, then we pop all the elements that are smaller than nums[k]
    3) We need to keep element just greater than nums[i] at the top, (this will be our nums[j])
    4) now we have nums[k] < nums[i] for finding nums[i] we need to an element smaller than nums[k]

    how do we find it - we have been keeping track of leftMin so,

                        if leftMin < nums[k], bingo
                        else leftMin = nums[k]

    Other Approaches -
        https://www.youtube.com/watch?v=8nx5dxFuvLo

*/
class Solution1 // O(n^3) - Brute Force 
{

public:
    bool find132pattern(vi nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] < nums[k] && nums[k] < nums[j])
                        return true;
                }
            }
        }
        return false;
    }
};
class Solution2 // O(n^2) gives TLE
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int leftMin = nums[0];
        for (int j = 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[k] > leftMin && nums[j] > nums[k])
                {
                    return true;
                }
            }
            leftMin = min(leftMin, nums[j]);
        }
        return false;
    }
};

class Solution // O(n), one pass solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<pii> st;
        int n = nums.size();
        int leftMin = nums[0];

        Fo(k, 1, n)
        {
            while (!st.empty() && nums[k] >= st.top().first)
            {
                st.pop();
            }
            if (!st.empty() && nums[k] > st.top().second)
            {
                return true;
            }
            st.push({nums[k], leftMin});
            leftMin = min(leftMin, nums[k]);
            debug(st.top().first, st.top().second);
        }
        return false;
    }
};

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

    Solution s;
    int n;
    read(n);
    vi nums(n);
    fo(i, n) read(nums[i]);
    bool res = s.find132pattern(nums); // store return value
    write(res);

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}