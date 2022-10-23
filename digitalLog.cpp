// #include <bits/stdc++.h>
// using namespace std;
// #define sync_off             \
//     ios::sync_with_stdio(0); \
//     cin.tie(0);
// #define ll long long int

// int main()
// {
//     sync_off;
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
// #endif
//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         int n;
//         cin >> n;
//         int a[n], b[n];
//         map<int, int> mpA;
//         map<int, int> mpB;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//             mpA[a[i]]++;
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin >> b[i];
//             mpB[b[i]]++;
//         }
//         int operation = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int mnFreqA = min(mpA[a[i]], mpB[a[i]]);
//             mpA[a[i]] -= mnFreqA;
//             mpB[a[i]] -= mnFreqA;

//             int mnFreqB = min(mpA[b[i]], mpB[b[i]]);
//             mpA[b[i]] -= mnFreqB;
//             mpB[b[i]] -= mnFreqB;
//         }
//         for (auto &it : mpA)
//         {
//             cout << it.first << " ";
//             if (it.first > 9)
//             {
//                 int x = log10(it.first) + 1;
//                 mpA[it.first]--;
//                 if (mpB.count(x))
//                 {
//                     mpB[x]--;
//                 }
//                 else
//                 {
//                     mpA[x]++;
//                 }
//             }
//         }
//         cout << endl;
//         for (auto &it : mpB)
//         {
//             if (it.first > 9)
//             {
//                 int x = log10(it.first) + 1;
//                 mpB[it.first]--;
//                 if (mpA.count(x))
//                 {
//                     mpA[x]--;
//                 }
//                 else
//                 {
//                     mpB[x]++;
//                 }
//             }
//         }
//         for (auto &it : mpA)
//         {
//             if (it.first != 1 && it.second > 0)
//             {
//                 operation += it.second;
//             }
//         }
//         for (auto &it : mpB)
//         {
//             if (it.first != 1 && it.second > 0)
//             {
//                 operation += it.second;
//             }
//         }
//         // cout << operation << endl;
//     }
//     return 0;
// }

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
    // Code Here
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        map<int, int> mpA;
        map<int, int> mpB;

        int input;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            mpA[input]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            if (mpA[input] > 0)
            {
                mpA[input]--;
            }
            else
            {
                mpB[input]++;
            }
        }
        int operation = 0;
        for (auto &it : mpA)
        {
            if (it.first > 9 && it.second > 0)
            {
                int count = it.second;

                int x = log10(it.first) + 1;
                operation += count;
                mpA[it.first] = 0;
                mpA[x] += count;
            }
        }
        for (auto &it : mpB)
        {
            if (it.first > 9 && it.second > 0)
            {
                int count = it.second;
                int x = log10(it.first) + 1;
                operation += count;
                mpB[it.first] = 0;
                mpB[x] += count;
            }
        }
        for (auto &it : mpA)
        {
            int num = it.first;
            int mn = min(mpA[num], mpB[num]);
            mpA[num] -= mn;
            mpB[num] -= mn;
        }
        for (auto &it : mpA)
        {
            // if (it.second > 0)
            //     cout << it.first << " ";
            if (it.first != 1 && it.second > 0)
            {
                operation += it.second;
            }
        }
        for (auto &it : mpB)
        {
            // if (it.second > 0)
            //     cout << it.first << " ";
            if (it.first != 1 && it.second > 0)
            {
                operation += it.second;
            }
        }
        cout << operation << endl;
    }
    return 0;
    // vector<int> a;
    // vector<int> b;
    // for (auto &itr : freqA)
    // {
    //     if (itr.second > 0)
    //     {
    //         int freq = itr.second;
    //         while (freq--)
    //             a.push_back(itr.first);
    //     }
    // }
    // for (auto &itr : mpB)
    // {
    //     int freq = itr.second;
    //     while (freq--)
    //         b.push_back(itr.first);
    // }
    // int ans = 0;
    // cout << a.size() << " " << b.size() << " ";
    // for (int i = 0; i < a.size(); i++)
    // {
    //     if(a[i] > 9){
    //         // 100 -> 3
    //     }
    // }
}