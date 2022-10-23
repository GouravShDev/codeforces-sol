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
    string s = "CONTEST";
    int n = 8;
    int arr[n] = {131, 13, 413, 432, 132, 425, 954, 234};
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
    }

    for (int i = 0; i < s.size() / 2; i++)
    {
        swap(s[i], s[n - 1 - i]);
    }
    int p = 1;
    while (p <= mx)
    {
        int last = s[0];
        for (int i = 0; i < n - 1; i++)
        {
            s[i] = s[i + 1];
        }
        s[n - 1] = last;
        p++;
    }
    cout << s << endl;
    return 0;
}