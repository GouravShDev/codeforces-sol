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
    int n;
    cin >> n;
    int count = 0;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a + b + c) > 1)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}