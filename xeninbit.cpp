#include <bits/stdc++.h>
using namespace std;
#define sync_off             \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long int

class SegmentTree
{
private:
    int *segmentTree;
    int numSize;
    int buildTree(vector<int> &nums, int index, int low, int high, bool &or_xor)
    {
        if (low == high)
        {
            or_xor = true;
            return segmentTree[index] = nums[low];
        }
        int mid = (low + high) / 2;
        int left = buildTree(nums, (2 * index) + 1, low, mid, or_xor);
        int right = buildTree(nums, (2 * index) + 2, mid + 1, high, or_xor);

        //
        if (or_xor)
        {
            or_xor = !or_xor;
            return segmentTree[index] = left | right;
        }
        else
        {
            or_xor = !or_xor;
            segmentTree[index] = left ^ right;
            //
            return segmentTree[index];
        }
    }
    void update(int index, int val, int i, int low, int high, bool &or_xor)
    {
        if (low == high)
        {
            segmentTree[index] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (mid >= i)
        {
            update((2 * index) + 1, val, i, low, mid, or_xor);
        }
        else
        {
            update((2 * index) + 2, val, i, mid + 1, high, or_xor);
        }
        if (or_xor)
        {
            or_xor = !or_xor;
            segmentTree[index] = segmentTree[(2 * index) + 1] | segmentTree[(2 * index) + 2];
        }

        else
        {
            or_xor = !or_xor;
            segmentTree[index] = segmentTree[(2 * index) + 1] ^ segmentTree[(2 * index) + 2];
        }
    }

public:
    SegmentTree(vector<int> &nums)
    {
        segmentTree = new int[4 * nums.size()];
        bool ox = true;
        buildTree(nums, 0, 0, nums.size() - 1, ox);

        numSize = nums.size();
    }

    void update(int index, int val)
    {
        bool ox = true;
        update(0, val, index, 0, numSize - 1, ox);
    }
    int getTop()
    {

        return segmentTree[0];
    }
};
int main()
{
    sync_off;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> nums(1 << n);
    vector<pair<int, int>> queries(m);
    for (int i = 0; i < (1 << n); i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }

    SegmentTree *sg = new SegmentTree(nums);
    for (int i = 0; i < m; i++)
    {
        sg->update(queries[i].first - 1, queries[i].second);
        cout << sg->getTop() << endl;
    }

    return 0;
}