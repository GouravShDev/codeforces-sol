#include <bits/stdc++.h>
using namespace std;
#define sync_off             \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long int
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        for (int i = n & 1; i < n - 2; i += 2)
            swap(p[i], p[i + 1]);
        for (int &x : p)
            cout << x << ' ';
        cout << '\n';
    }
}