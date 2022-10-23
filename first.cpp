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
        int n, m;
        cin >> n >> m;
        int x[m], y[m];
        int board[n][n] = {0};
        for (int i = 0; i < m; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> y[i];
        }
        // int flag = 0;
        // for (int i = 0; i < m; i++)
        // {
        //     if (isPossible(board, n, x[i], y[i]))
        //     {
        //         flag = 1;
        //         break;
        //     }
        // }
        if (m < n)
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