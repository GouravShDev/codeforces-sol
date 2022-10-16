#include <bits/stdc++.h>
using namespace std;
#define sync_off             \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long int

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
        map<int, int> mp;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]] = i + 1;
        }
        int ans = -1;
        for (auto &it : mp)
        {
            int cur = it.first;
            for (auto &it2 : mp)
            {
                if (gcd(cur, it2.first) == 1)
                {
                    ans = max(ans, it.second + it2.second);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}