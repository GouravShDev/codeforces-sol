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
        int n, m;
        cin >> n >> m;
        if (n == 1 || m == 1)
        {
            cout << n << " " << m;
        }
        else
        {
            cout << n - 1 << " " << m - 1;
        }
        cout << endl;
    }
    return 0;
}