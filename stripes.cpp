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
        string strIP[8];
        for (int i = 0; i < 8; i++)
        {
            cin >> strIP[i];
        }
        int flag = 1;
        for (int i = 0; i < 8; i++)
        {
            flag = 1;
            for (int j = 0; j < 8; j++)
            {
                if (strIP[i][j] == '.' || strIP[i][j] != 'R')
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                cout << 'R' << endl;
                break;
            }
            for (int j = 0; j < 8; j++)
            {
                if (strIP[j][i] == '.' || strIP[j][i] != 'R')
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                cout << 'R' << endl;
                break;
            }
        }
        if (!flag)
        {
            cout << 'B' << endl;
        }
    }
    return 0;
}