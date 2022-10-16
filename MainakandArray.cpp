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
        int firstFix = *(max_element(arr, arr + n)) - arr[0];
        int lastFix = arr[n - 1] - *(min_element(arr, arr + n));
        int adjMax = arr[n - 1] - arr[0];
        for (int i = 0; i < n; ++i)
        {
            adjMax = max(adjMax, arr[i] - arr[(i + 1) % n]);
        }
        int ans = max({firstFix, lastFix, adjMax});
        cout << ans << endl;
    }
    return 0;
}
