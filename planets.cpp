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
        int n, c;
        cin >> n >> c;
        int arr[n];
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int ans = 0;
        for (auto &m : mp)
        {
            if (m.second > c)
            {
                ans += c;
            }
            else
            {
                ans += m.second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}