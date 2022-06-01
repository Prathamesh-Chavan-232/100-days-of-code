
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
    Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    Problem - Letter combinations of a phone number
    Difficulty - Medium
    topic - Back tracking
    Status - Solved
    Date - 10/5/22 & 17/5/22
*/
/*  Approach -

    e.g -> 2,3,4
        first digit - 
    2                        ""
                     /      |        \
                   a        b         c
                 / \ \    / \ \    / | \ 
    3           d e f     d e f    d e f
            ... and so on for the next digit

    therefore we need to traverse the letter combinations of each number, 
    and back track for other choices in the tree    
*/
class Solution
{
    vi nums;
    vector<string> res;
    const vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    void generate(string &combination, int i)
    {
        if (combination.size() == nums.size())
        {
            res.pb(combination);
            return;
        }
        int currNum = nums[i];       // Current number between 2 - 9
        string s = letters[currNum]; // string of letters corresponding to current number
        debug(s);
        for (auto ch : s)
        {
            combination.pb(ch);
            generate(combination, i + 1);
            combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        int n = letters.size();
        if (digits == "")
        {
            res.pb("");
            return res;
        }
        fo(i, digits.size())
        {
            int temp = digits[i] - '0';
            nums.push_back(temp);
            debug(temp);
        }
        string combination = "";
        generate(combination, 0);
        return res;
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
    string digits;
    cin >> digits;
    vector<string> res = s.letterCombinations(digits); // store return value
    for (auto &str : res)
    {
        cout << str << " ";
    }
    cout << "\n";

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}