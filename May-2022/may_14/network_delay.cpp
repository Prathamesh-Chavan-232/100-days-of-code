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

// Function definitions
void Add_edge(int v1, int v2, int w);
void dfs(int vertex);

// constants
const int mod = 1'000'000'007;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;
vpii graph[N]; // For Adjacency List
bool vis[N];
int ct = 0;

/*
    Link - https://leetcode.com/problems/network-delay-time/
    Problem - Network time delay
    Difficulty - Medium (Dijikstra's algorithm)
    contest - No
    Status - Solved
    Date - 14/5/22
*/
/*  Approach -
        Use Dijikstra's algorithm to find the shortest path to every node from the given source
        node.
        Shortest path in this case represents time required to reach that node
        In Dijikstra initially all weight values are set to infinity, if some value is still infinity
        then it means that we never reached that node, so our answer will be -1 (cant reach every node)

        if we do reach every node, then the answer will time taken to reach the farthest node.
*/

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        for (auto &v : times)
        {
            Add_edge(v[0], v[1], v[2]);
        }

        priority_queue<pii, vpii, greater<pii>> pq; // store -> {distance from source, node}
        vi dist(n + 1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty())
        {
            pii top = pq.top();
            pq.pop();
            int u = top.second; //  select closest node
            if (vis[u])
                continue;               // If already visited node is popped we don't visit it
            vis[u] = true;              // mark selected node as visited;
            for (auto child : graph[u]) // checking every neighbour of current node
            {
                int v = child.first;   // neighbour node
                int wt = child.second; // distance if neighbour from source node
                if (vis[v] == false && dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int res = 0;
        Fo(i, 1, dist.size()) // finding the farthest node
        {

            res = max(res, dist[i]);
        }
        if (res == INT_MAX)
            return -1;
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
    int res; // store return value
    int n, m, k;
    cin >> n >> m >> k;

    vvi times;
    fo(i, m)
    {
        vi temp;
        fo(j, 3)
        {
            int v;
            cin >> v;
            temp.pb(v);
        }
        times.pb(temp);
    }
    for (auto v : times)
    {
        debcon(v);
    }
    res = s.networkDelayTime(times, n, k);
    cout << res << "\n";

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}

void Add_edge(int v1, int v2, int w)
{
    graph[v1].push_back({v2, w});
    // graph[v2].push_back({v1, w});*/ihoh9
}