#include <bits/stdc++.h>
using namespace std;

/*
    Link - https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
    Problem - Find corresponding node in cloned tree
    Difficulty - Easy (but listed medium)
    topic - DFS / BFS
    Status - Solved
    Date - 17/5/22
*/
/*  Approach -
        Traverse both trees parallely and once u find target in the original tree, 
        the current node of the cloned tree should also have the same element.
        therefore ans = current node of cloned tree.
*/


/**
 * Definition for a binary tree node.
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{

    TreeNode *ans, *target;

public:
    void preorder(TreeNode *original, TreeNode *cloned)
    {
        if (original == NULL)
            return;
        if (original == target)
            ans = cloned;
        preorder(original->left, cloned->left);
        preorder(original->right, cloned->right);
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        this->target = target;
        preorder(original, cloned);
        return ans;
    }
};

void code()
{
    Solution s;
    int res; // store return value
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
