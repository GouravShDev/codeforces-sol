#include <bits/stdc++.h>
using namespace std;
#define sync_off             \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long int

int countX(string str)
{
    int count = 0;
    int i = 0;
    while (i < str.size() && str[i] == 'X')
    {

        count++;
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
        string str1, str2;
        cin >> str1 >> str2;
        int n = str1.size();
        int m = str2.size();
        if (str1[n - 1] == 'S' && str2[m - 1] != 'S')
        {
            cout << "<";
        }
        else if (str1[n - 1] != 'S' && str2[m - 1] == 'S')
        {
            cout << ">";
        }
        else if (str1[n - 1] == 'L' && str2[m - 1] != 'L')
        {
            cout << ">";
        }
        else if (str1[n - 1] == 'L' && str2[m - 1] != 'L')
    }
    return 0;
}