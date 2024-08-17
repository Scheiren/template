#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 10, mod = 1e9 + 7;
const long long maxN = 2e5 + 1;

struct Node
{
    int maxVal = -INF, lazy = 0;
    Node *left = NULL, *right = NULL;
};

class SegmentTree
{
public:
    void addLazy(Node *&root, int val)
    {
        if (root == NULL)
        {
            return;
        }
        root->maxVal += val;
        root->lazy += val;
    }
    void lazyExecutePlus(Node &root)
    {
        addLazy(root.left, root.lazy);
        addLazy(root.right, root.lazy);

        root.lazy = 0;
    }
    void update(Node &root, int val, int position, int left, int right)
    {
        if (left == right)
        {
            root.maxVal = max(root.maxVal, val);
            return;
        }
        lazyExecutePlus(root);
        int mid = (left + right) / 2;
        if (position <= mid)
        {
            if (root.left == NULL)
            {
                root.left = new Node();
            }

            update(*root.left, val, position, left, mid);
            root.maxVal = max(root.maxVal, root.left->maxVal);
        }
        else
        {
            if (root.right == NULL)
            {
                root.right = new Node();
            }

            update(*root.right, val, position, mid + 1, right);
            root.maxVal = max(root.maxVal, root.right->maxVal);
        }
    }

    void updateRangePlus(Node &root, int val, int posLeft, int posRight, int left, int right)
    {
        if (left >= posLeft && right <= posRight)
        {
            root.maxVal += val;
            root.lazy += val;
            return;
        }
        lazyExecutePlus(root);
        int mid = (left + right) / 2;
        if (posLeft <= mid)
        {
            if (root.left == NULL)
            {
                root.left = new Node();
            }

            updateRangePlus(*root.left, val, posLeft, posRight, left, mid);
            root.maxVal = max(root.maxVal, root.left->maxVal);
        }
        if (posRight > mid)
        {
            if (root.right == NULL)
            {
                root.right = new Node();
            }

            updateRangePlus(*root.right, val, posLeft, posRight, mid + 1, right);
            root.maxVal = max(root.maxVal, root.right->maxVal);
        }
    }
    void build(Node &root, vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            update(root, v[i], i, 0, v.size() - 1);
        }
    }
};

class Solution
{
public:
    void solve()
    {
        vector<int> v = {9, 1, 6, 5, 3};
        Node root;

        SegmentTree().build(root, v);
        cout << 1;

        SegmentTree().updateRangePlus(root, 6, 0, 3, 0, v.size() - 1);
        cout << 2;

        SegmentTree().updateRangePlus(root, 6, 2, 4, 0, v.size() - 1);
        cout << 3;

        return;
    }
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Solution().solve();

    return 0;
}
