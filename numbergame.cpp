#include <bits/stdc++.h>
using namespace std;
#define sync_off             \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long int

bool isPossible(multiset<int> st, int k)
{
    while (k--)
    {
        auto mxIt = prev(st.upper_bound(k));
        if (mxIt != st.end())
        {
            st.erase(mxIt);
            if (st.empty() && k > 0)
                return false;
            int mnValue = *st.begin();
            st.erase(mnValue);
            mnValue += k;
            st.insert(mnValue);
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    sync_off;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int arr[n];
        multiset<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            st.insert(arr[i]);
        }
        int ans = 0;
        int flag = 0;
        for (int i = n; i >= 0; i--)
        {
            if (isPossible(st, i))
            {
                flag = 1;
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}