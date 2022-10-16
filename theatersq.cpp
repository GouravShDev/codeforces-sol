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
    double n, m, a;
    cin >> n >> m >> a;
    cout << (ll)ceil(n / a) * (ll)ceil(m / a);
    return 0;
}