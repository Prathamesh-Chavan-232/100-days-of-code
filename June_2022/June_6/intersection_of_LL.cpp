#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        while (ptr1 != ptr2)
        {
            if (ptr1 == NULL)
            {
                ptr1 = headB;
            }
            else
            {
                ptr1 = ptr1->next;
            }
            if (ptr2 == NULL)
            {
                ptr2 = headA;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        return ptr1;
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