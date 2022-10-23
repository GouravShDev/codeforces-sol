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

        int arr[n];
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> s;
        if (n != (int)s.size())
        {
            cout << "NO\n";
            continue;
        }
        map<int, char> mp;
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i]) != mp.end() && mp[arr[i]] != s[i])
            {
                flag = 0;
                break;
            }
            mp[arr[i]] = s[i];
        }
        if (!flag)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
        cout << endl;
    }
    return 0;
}