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
        int n, q;
        cin >> n >> q;
        ll arr[n];
        ll preMx[n];
        ll preSum[n];
        ll ques[q];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i > 0)
            {
                preMx[i] = max(arr[i], preMx[i - 1]);
                preSum[i] = arr[i] + preSum[i - 1];
            }
            else
            {
                preMx[i] = arr[i];
                preSum[i] = arr[i];
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << preSum[i] << " ";
        // }
        // cout << endl;

        for (int i = 0; i < q; i++)
        {
            cin >> ques[i];
            int index = upper_bound(preMx, preMx + n, ques[i]) - preMx;
            // cout << index << " ";
            ques[i] = index > 0 ? preSum[index - 1] : 0;
        }
        for (int i = 0; i < q; i++)
        {
            cout << ques[i] << " ";
        }
        cout << endl;
    }
    return 0;
}