#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define pb push_back
#define mp make_pair

// Typdefs for containers
typedef vector<int> vi;
typedef vector<ll> vl;


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

*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
    int ct = 0;
    vector<int> flattenList;
public:

    void dfs(NestedInteger x) // x -> integer || list
    {
        if(x.isInteger())
        {
            flattenList.pb(x.getInteger());       
        }
        else
        {
            for(auto val : x.getList()) // again dfs on each value in the list
            {
                dfs(val);
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        int n = nestedList.size();
        fo(i, n)
        {
            dfs(nestedList[i]);
        }
    }

    int next()
    {
        return flattenList[ct++];
    }

    bool hasNext()
    {
        if(ct < flattenList.size())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */