#include <bits/stdc++.h>
using namespace std;
#define sync_off             \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long int

bool solve(vector<int> arr, int i, int degree)
{
    if (i >= arr.size())
    {
        return (degree % 360 == 0);
    }
    if (solve(arr, i + 1, degree - arr[i]))
        return true;
    if (solve(arr, i + 1, degree + arr[i]))
        return true;
    return false;
}

int main()
{
    sync_off;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (solve(arr, 0, 360))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;
    return 0;
}