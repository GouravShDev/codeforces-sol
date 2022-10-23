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
        ll a[n], b[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        ll i = 0;
        ll j = n - 1;
        ll time = 0;
        while (i <= j)
        {
            if (b[i] < b[j])
            {
                time += a[i];
                if (i < j)
                    a[i + 1] += b[i];
                i++;
            }
            else
            {
                time += a[j];
                if (j > i)
                    a[j - 1] += b[j];
                j--;
            }
        }
        cout << time << endl;
    }
    return 0;
}