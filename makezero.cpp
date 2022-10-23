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

        int curSum = 0;
        int targetSum = 0;
        int addOrSub = 1;
        int start = 1;
        int end;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (!addOrSub)
                arr[i] = -arr[i];
            curSum += arr[i];
            // cout << curSum << " : " << targetSum << endl;
            addOrSub = !addOrSub;
            if (curSum < 0)
            {
                ans.push_back({start, i + 1});
                start = i + 2;
                targetSum = -curSum;
                curSum = 0;
                addOrSub = 1;
            }
            else if (curSum == targetSum)
            {
                addOrSub = 1;
                ans.push_back({start, i + 1});
                start = i + 2;
                curSum = 0;
                targetSum = 0;
            }
        }
        if (curSum == 0)
        {
            cout << ans.size() << endl;
            for (auto &x : ans)
            {
                cout << x.first << " " << x.second << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}