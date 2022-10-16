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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> zero, one;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (a[i])
            {
                one.push_back(x);
            }
            else
            {
                zero.push_back(x);
            }
        }
        sort(one.begin(), one.end());
        sort(zero.begin(), zero.end());
        int oneI = 0, oneJ = one.size() - 1;
        int zeroI = 0, zeroJ = zero.size() - 1;
        int ans = 0;
        while (oneI <= oneJ && zeroI <= zeroJ)
        {
            // if(flag){
            if (one[oneI] < zero[zeroI])
            {
                ans += one[oneI++];
                if (zeroJ >= 0)
                {
                    ans += 2 * zero[zeroJ--];
                }
            }
            else
            {
                ans += zero[zeroI++];
                if (oneJ >= 0)
                {
                    ans += 2 * one[oneJ--];
                }
            }
        }
        while (oneI <= oneJ)
        {
            ans += one[oneI++];
        }
        while (zeroI < zeroJ)
        {
            ans += zero[zeroI++];
        }
        cout << ans << endl;
    }
    return 0;
}