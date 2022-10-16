#include <bits/stdc++.h>
using namespace std;
#define sync_off             \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long int
class Node
{
public:
    int closing;
    int opening;
    int pair;
    Node()
    {
        closing = 0;
        opening = 0;
        pair = 0;
    };
    Node(int cB, int oB, int pB)
    {
        closing = cB;
        opening = oB;
        pair = pB;
    }
};
class SegmentTree
{
    Node **segmentTree;
    int low;
    int high;
    int size;

public:
    SegmentTree(string &brackets)
    {
        int Treesize = 4 * brackets.size();
        low = 0;
        high = brackets.size() - 1;
        segmentTree = new Node *[Treesize];
        buildTree(low, high, 0, brackets);
    }

    Node *buildTree(int low, int high, int index, string &brackets)
    {

        if (low == high)
        {
            int o = (brackets[low] == '(');
            int c = (brackets[low] == ')');
            Node *node = new Node(c, o, 0);
            return segmentTree[index] = node;
        }
        int mid = (low + high) / 2;

        Node *left = buildTree(low, mid, 2 * index + 1, brackets);
        Node *right = buildTree(mid + 1, high, 2 * index + 2, brackets);
        int newPair = min(left->opening, right->closing);
        int p = left->pair + right->pair + newPair;
        int o = left->opening + right->opening - newPair;
        int c = left->closing + right->closing - newPair;
        Node *node = new Node(c, o, p);
        return segmentTree[index] = node;
    }

    int search(int l, int r)
    {
        Node *node = searchPairs(l, r, low, high, 0);
        return node->pair;
    }

    Node *searchPairs(int l, int r, int low, int high, int treeIndex)
    {
        if (l > high || r < low) //  L H l || l r L
        {
            return new Node(0, 0, 0);
        }
        else if (l <= low && r >= high) // l L H r
        {
            return segmentTree[treeIndex];
        }
        int mid = (low + high) / 2;
        Node *left = searchPairs(l, r, low, mid, 2 * treeIndex + 1);
        Node *right = searchPairs(l, r, mid + 1, high, 2 * treeIndex + 2);
        int newPair = min(left->opening, right->closing);
        int p = left->pair + right->pair + newPair;
        int o = left->opening + right->opening - newPair;
        int c = left->closing + right->closing - newPair;
        Node *node = new Node(c, o, p);
        return node;
    }
    int top()
    {
        return segmentTree[0]->pair;
    }
};

int main()
{
    sync_off;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    // Code Here
    string input;
    int q;
    cin >> input >> q;
    vector<pair<int, int>> queries(q);

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }
    SegmentTree t(input);
    for (auto &qry : queries)
    {
        cout << t.search(qry.first - 1, qry.second - 1) * 2 << endl;
    }

    return 0;
}