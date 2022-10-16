#include <bits/stdc++.h>
using namespace std;
#define sync_off             \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long int
class Node
{
public:
    int oBracket;
    int cBracket;
    int cPair;

    Node()
    {
        this->cBracket = 0;
        this->cPair = 0;
        this->oBracket = 0;
    }
    Node(int o, int c, int comp)
    {
        this->oBracket = o;
        this->cBracket = c;
        this->cPair = comp;
    }
};
class SegmentTree
{
    Node **segTree;
    int sz;

    Node *buildTree(string &s, int treeIndex, int low, int high)
    {
        if (low == high)
        {
            Node *node = new Node((int)s[low] == '(', (int)s[low] == ')', 0);
            segTree[treeIndex] = node;
            // cout << segTree[treeIndex]->cBracket << endl;
            return segTree[treeIndex];
        }
        int mid = (low + high) / 2;
        Node *left = buildTree(s, (treeIndex * 2) + 1, low, mid);
        Node *right = buildTree(s, (treeIndex * 2) + 2, mid + 1, high);

        int newPair = min(left->oBracket, right->cBracket);
        int opBr = left->oBracket + right->oBracket - newPair;
        int clBr = right->cBracket + left->cBracket - newPair;
        int compBr = left->cPair + right->cPair + newPair;
        segTree[treeIndex] = new Node(opBr, clBr, compBr);
        // cout << treeIndex << " : " << segTree[treeIndex]->cBracket << endl;
        return segTree[treeIndex];
    }

    Node *search(int treeIndex, int low, int high, int l, int r)
    {
        if (l > high || r < low)
        {
            return new Node();
        }
        if (l <= low && high <= r)
        { // l Low High r
            return segTree[treeIndex];
        }
        int mid = (low + high) / 2;
        Node *left = search((treeIndex * 2) + 1, low, mid, l, r);
        Node *right = search((treeIndex * 2) + 2, mid + 1, high, l, r);

        int newPair = min(left->oBracket, right->cBracket);
        int opBr = left->oBracket + right->oBracket - newPair;
        int clBr = right->cBracket + left->cBracket - newPair;
        int compBr = left->cPair + right->cPair + newPair;
        return new Node(opBr, clBr, compBr);
    }

public:
    SegmentTree(string &s)
    {
        sz = s.size();
        segTree = new Node *[4 * sz];
        buildTree(s, 0, 0, s.size() - 1);
    }
    int getCmpBr()
    {
        return segTree[0]->cPair;
    }
    int search(int l, int r)
    {
        return search(0, 0, sz - 1, l, r)->cPair;
    }
};

int main()
{
    sync_off;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string ipString;
    cin >> ipString;
    SegmentTree *segTree = new SegmentTree(ipString);
    // cout << 2 * segTree->getCmpBr();
    int qN;
    cin >> qN;
    while (qN--)
    {
        int l, r;
        cin >> l >> r;
        cout << 2 * segTree->search(l - 1, r - 1) << endl;
    }
    return 0;
}