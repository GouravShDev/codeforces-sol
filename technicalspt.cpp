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
        string s;
        cin >> s;
        int q = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'Q')
            {
                q++;
            }
            else
            {
                q--;
            }
            if (q < 0)
            {
                q = 0;
            }
        }
        if (q > 0)
        {
            cout << "No";
        }
        else
        {
            cout << "Yes";
        }
        cout << endl;
    }

    return 0;
}