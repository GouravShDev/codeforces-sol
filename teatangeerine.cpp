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
        int arr[n];
        int mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mn = min(arr[i], mn);
        }
        mn *= 2;
        mn--;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mn)
            {
                int count = arr[i] / mn;
                if (arr[i] % mn == 0)
                {
                    count--;
                }
                ans += count;
            }
        }
        cout << ans << endl;
    }
    return 0;
}