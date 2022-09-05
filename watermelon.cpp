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

    int w;
    cin >> w;
    if (w == 2)
    {
        cout << "NO";
    }
    else
    {
        if (w & 1)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
    }
    return 0;
}