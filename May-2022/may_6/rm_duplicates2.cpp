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

// Debugging tools
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif

// Function definitions
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
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
    Link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
    Problem - Remove all adjacent duplicates 2
    Difficulty - Medium
    contest - No (daily challenge May 2022)
    Status - Solved
    Date - 6/5/22
*/
/*  Approach -
        Input: s = "deeedbbcccbdaa", k = 3

        We take a stack and push each element inside it 
        if theyre not equal to st.top()

        We push elements in pairs like {'d', 1} {char, occurence}
        
        if s[i] == st.top()
        we increment st.top().second 

        eg. after adding e once the stack will be 
            {e,1}  ___   {e,2} 
            {d,1}        {d,1}        
        here we increment
        Once the second value becomes equal to k,
        we pop that element

    after this, inside stack we have the required elements 
    along with their occurences, so we append them to a string
    & reverse the string
*/

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.length();
        if (n < k)
            return s;
        stack<pair<char, int>> st;
        fo(i, n)
        {
            debug(i);
            if (st.empty() || st.top().first != s[i])
            {
                st.push({s[i], 1});
            }
            else if (st.top().first == s[i])
            {
                st.top().second++;
            }
            if (st.top().second == k)
            {
                st.pop();
            }
        }
        string res;
        while (!st.empty())
        {
            while (st.top().second--)
            {
                res.pb(st.top().first);
            }
            st.pop();
        }
        reverse(all(res));
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

    int k;
    string str;
    read(str, k);
    Solution s;
    string res = s.removeDuplicates(str, k); // store return value
    write(res);

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}