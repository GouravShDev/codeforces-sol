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
        int a[n];
        int b[n];
        int oneCountA = 0;
        int oneCountB = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i])
                oneCountA++;
        }
        int isAEqB = 1;
        int xorCount = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i])
                oneCountB++;
            if (a[i] != b[i])
            {
                isAEqB = 0;
            }
            if (a[i] ^ b[i] > 0)
            {
                xorCount++;
            }
        }

        if (isAEqB)
        {
            cout << 0;
        }
        else if (oneCountA == oneCountB)
        {
            cout << 1;
        }
        else
        {
            int dif = abs(oneCountA - oneCountB);
            if (xorCount > dif)
            {
                cout << dif + 1;
            }
            else
            {
                cout << dif;
            }
        }
        cout << endl;
    }
    return 0;
}