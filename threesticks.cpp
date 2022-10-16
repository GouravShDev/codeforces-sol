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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int ans = INT_MAX;
        for (int i = 1; i < n - 1; i++)
        {
            int x = abs(arr[i - 1] - arr[i]);
            int y = arr[i + 1] - arr[i];
            ans = min(ans, x + y);
        }

        cout << ans << endl;
    }
    return 0;
}