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
        int i = 0;
        int cur = arr[i++];
        vector<int> ans;
        ans.push_back(cur);
        int flag = 0;
        while (i < n)
        {
            if (arr[i] > 0 && (cur - arr[i]) >= 0)
            {
                flag = 1;
                break;
            }
            cur += arr[i++];
            ans.push_back(cur);
        }
        if (flag)
        {
            cout << -1;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}