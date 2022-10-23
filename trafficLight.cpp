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
        char curlight;
        cin >> n >> curlight;
        string lights;
        cin >> lights;
        int len = -1;
        if (curlight == 'g')
        {
            cout << 0 << endl;
            continue;
        }
        // int i =0;
        // while(true){
        //     i= (i+1)
        // }
        int ans = 0;
        for (int j = 0; j < 2 * n; j++)
        {
            int i = j % n;
            if (len == -1 && curlight == lights[i])
            {
                len = 0;
            }
            else if (len != -1 && lights[i] == 'g')
            {
                len++;
                ans = max(ans, len);
                len = -1;
            }
            else if (len != -1)
            {
                len++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}