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
        string ans = "";
        bool flag = 0;
        for (int i = 0; i < 10; i++)
        {
            int firstOcc = -1;
            for (int j = s.size() - 1; j >= 0; j--)
            {
                if (s[j] == i + '0' && firstOcc == -1)
                {
                    firstOcc = j;
                }
                if (s[j] > (i + '0') && firstOcc != -1)
                {
                    flag = 1;
                }
                if (flag)
                {
                    // cout << s[j] << endl;
                    if (s[j] == '9')
                    {
                        ans += '9';
                    }
                    else if (s[j] > (i + '0'))
                    {
                        ans += '1' + (s[j] - '0');
                    }
                    else
                    {
                        ans += s[j];
                    }
                }
            }
            // cout << "=>" << firstOcc << endl;

            while (flag && firstOcc < s.size())
            {
                // cout << s[firstOcc] << " ";
                ans += s[firstOcc++];
            }
            if (flag)
                break;
        }
        if (ans == "")
        {
            ans = s;
        }
        sort(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}