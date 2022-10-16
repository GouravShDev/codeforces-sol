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
        if ((a == (b + c)) || (b + a == c) || (b == a + c))
        {
            cout << "YES";
        }
        else
        {

            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}