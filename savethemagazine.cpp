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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        int i = 0;
        while (i < n)
        {
            if (s[i] == '0')
            {

                int mn = arr[i];
                ans += arr[i++];
                while (i < n && (s[i] == '1'))
                {
                    mn = min(arr[i], mn);
                    ans += arr[i];
                    i++;
                }
                ans -= mn;
            }
            else
            {
                ans += arr[i++];
            }
        }
        // if (s[n - 1] == '1')
        // {
        //     ans += arr[n - 1];
        // }
        cout << ans << endl;
    }
    return 0;
}