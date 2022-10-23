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
        int i = (n + 1) / 2;
        int j = n;
        for (; i > 0 && j > (n + 1) / 2; i--, j--)
        {
            cout << i << " " << j << " ";
        }
        if (i > 0)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}