#include <io.h>
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

#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif

#ifndef ONLINE_JUDGE
#define debmap(x)        \
    cerr << #x << " = "; \
    _printmap(x);        \
    cerr << "\n";
#else
#define debmap(x)
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

template <typename T>
void _print(T const &c) // print any type of vector / set
{
    cerr << "{ ";
    foreach (it, c)
        cerr << *it << ", ";
    cerr << "}";
}

template <typename T, typename U>
void _printmap(map<T, U> m)
{
    cerr << "{ ";
    formap(m)
    {
        cerr << "{" << key << "," << value << "} ";
    }
    cerr << "}";
}
// Varadiac I/O
template <typename... T>
void r(T &...args)
{
    ((cin >> args), ...);
}
template <typename... T>
void w(T &&...args)
{
    ((cout << args << " "), ...);
    cout << "\n";
}
// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

/*
    Link -
    Problem -
    Difficulty -
    contest -
    Status -
    Date -
*/
/*  Approach -

    1) making push costly -

        i)   pop all the elements of q1 & push into q2
        ii)  push x into q1
        iii) pop all of q2 & push into q1
        Here top() & pop() operation stays same

        e.g. - consider that 1,2 are already in stack and we are pushing 3
            q1 -> 2 1  -> 1 -> empty
            q2-> empty -> 2 1
            q1 -> 3
            q2 -> 2 1 -> empty, q1 -> 3 2 1


    2) Making pop costly -
        i)   Pop all elements except the last element from q1, push them in q2
        ii)  Pop in q1
        iii) Push all elements from q2 to q1
        iv)  For top, in step ii) instead of pop, pop & push front in q2
    Here pop and top are different

    e.g. - consider the stack - 1,2,3 pop_back (i.e. pop 3)
        q1 -> 1 2 3, q2 -> empty
        q1 -> empty -> 3, q2 -> empty -> 1 2
        q1 -> 3 -> empty
        q2 -> 1 2, -> empty, q1 -> empty -> 1 2

    3) Using only 1 queue -
        i)  for pushing - push the element at the back,
        ii) pop rest of the elements and push them at the back

        e.g consider stack = 1 2 push 2
        push 3
        q -> 2 1, size = 2
        q -> 2 1 3 -> 3 2 1(pop & push  until size==0)
*/

class MyStack1
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop()
    {
        int res = q1.front();
        q1.pop();
        return res;
    }

    int top()
    {
        int res = q1.front();
        return res;
    }

    bool empty()
    {
        bool res = q1.empty();
        return res;
    }
};

class MyStack2
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x)
    {
        q1.push(x);
    }
    int pop()
    {
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }

    int top()
    {
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int res = q1.front();
        q2.push(q1.front());
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }

    bool empty()
    {
        bool res = q1.empty();
        return res;
    }
};

class MyStack
{

    queue<int> q;

public:
    MyStack() {}

    void push(int x)
    {
        int count = q.size();
        q.push(x);
        while (count)
        {
            q.push(q.front());
            q.pop();
            count--;
        }
    }

    int pop()
    {
        int res = q.front();
        q.pop();
        return res;
    }

    int top()
    {
        int res = q.front();
        return res;
    }

    bool empty()
    {
        bool res = q.empty();
        return res;
    }
};
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

    MyStack s;
    int res;
    bool mt;

    s.push(3);
    s.push(5);
    s.push(1);

    while (!s.empty())
    {
        /* code */
        int res = s.pop();
        cout << res << endl;
    }

#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}
