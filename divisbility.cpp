#include <bits/stdc++.h>
using namespace std;
#define sync_off             \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long int
int getFactor(int n)
{
    int count = 0;
    while (n && n % 2 == 0)
    {
        count++;
        n /= 2;
    }
    return count;
}
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
        int powerSum = 0;
        vector<int> fac2;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] = arr[i] & 1 ? 0 : getFactor(arr[i]);
            powerSum += arr[i];
            fac2.push_back(getFactor(i + 1));
            // cout << arr[i] << " ";
        }
        sort(fac2.begin(), fac2.end());
        // cout << endl;

        // cout << powerSum << endl;
        if (powerSum >= n)
        {
            cout << 0 << endl;
            continue;
        }
        int op = 0;
        int flag = 0;
        for (int i = fac2.size() - 1; i >= 0; i--)
        {
            powerSum += fac2[i];
            op++;
            if (powerSum >= n)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {

            cout << op << endl;
        }
        else
        {

            cout << -1 << endl;
        }
    }
    return 0;
}