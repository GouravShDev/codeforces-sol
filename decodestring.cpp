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
        int x;
        cin >> x;
        string input;
        cin >> input;
        int n = input.size();
        string ans = "";
        int i = n - 1;
        while (i >= 0)
        {
            if (input[i] == '0')
            {
                int num = (input[i - 2] - '0') * 10 + (input[i - 1] - '0');
                // cout << num;
                ans += 'a' + num - 1;
                i -= 3;
            }
            else
            {
                ans += 'a' + (input[i] - '0') - 1;
                i--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}