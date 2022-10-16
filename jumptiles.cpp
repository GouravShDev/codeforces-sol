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
        string s;
        cin >> s;
        int n = s.size();
        int mCost = abs(s[n - 1] - s[0]);
        vector<int> path;
        multimap<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp.insert({s[i], i});
        }
        if (s[0] <= s[n - 1])
        {
            for (auto &m : mp)
            {
                if (m.first <= s[n - 1] && m.first >= s[0])
                {
                    path.push_back(m.second + 1);
                }
            }
        }
        else
        {

            for (auto &m : mp)
            {
                if (m.first >= s[n - 1] && m.first <= s[0])
                {
                    path.push_back(m.second + 1);
                }
            }
        }
        int cost = 0;
        for (int i = 1; i < path.size(); i++)
            cost += abs(s[path[i] - 1] - s[path[i - 1] - 1]);

        sort(path.begin(), path.end());
        cout << cost << " " << path.size() << endl;
        for (auto &it : path)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}