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
        int a, b, c;
        cin >> a >> b >> c;
        int a1 = abs(a - 1);
        int b1 = abs(b - c) + abs(c - 1);
        if (a1 < b1)
        {
            cout << 1;
        }
        else if (a1 > b1)
        {
            cout << 2;
        }
        else
        {
            cout << 3;
        }
        cout << endl;
    }
    return 0;
}