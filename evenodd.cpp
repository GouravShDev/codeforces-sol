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
        long long arr[n];
        int oddCount = 0;
        int evenCount = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] & 1)
            {
                oddCount++;
            }
            else
            {
                evenCount++;
            }
            sum += arr[i];
        }
        // long long curSum = sum;
        for (int i = 0; i < q; i++)
        {
            long long type, x;
            cin >> type >> x;
            // EVEN
            if (type == 0)
            {
                sum += evenCount * x;
                if (x & 1)
                {
                    oddCount += evenCount;
                    evenCount = 0;
                }
            }
            // ODD
            else
            {
                sum += oddCount * x;
                if (x & 1)
                {
                    evenCount += oddCount;
                    oddCount = 0;
                }
            }
            cout << sum << endl;
        }
    }

    return 0;
}