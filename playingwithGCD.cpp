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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> newArr;
        newArr.push_back(arr[0]);
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] > arr[i] && arr[i + 1] % arr[i] == 0)
            {
                newArr.push_back(arr[i + 1]);
            }
            else
            {
                newArr.push_back(arr[i] * arr[i + 1]);
            }
        }
        newArr.push_back(arr[n - 1]);
        int flag = 0;
        for (int i = 0; i < newArr.size() - 1; i++)
        {
            int gc = gcd(newArr[i], newArr[i + 1]);
            if (gc != arr[i])
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
        cout << endl;
    }
    return 0;
}