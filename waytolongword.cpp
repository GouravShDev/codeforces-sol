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
        string s;
        cin >> s;
        if (s.size() > 10)
        {
            string ans = "";
            ans += s[0];
            ans += to_string(s.size() - 2);
            ans += s[s.size() - 1];
            cout << ans << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
    return 0;
}