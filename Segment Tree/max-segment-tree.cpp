struct Node
{
    int val, maxVal;
    Node *left = NULL, *right = NULL;
};

class SegmentTree
{
public:
    void update(Node &root, int val, int position, int left, int right)
    {
        if (left == right)
        {
            root.val = val;
            root.maxVal = max(root.maxVal, val);
            return;
        }
        int mid = (left + right) / 2;
        if (position <= mid)
        {
            if (root.left == NULL)
            {
                root.left = new Node();
            }

            root.maxVal = max(root.maxVal, val);
            update(*root.left, val, position, left, mid);
        }
        else
        {
            if (root.right == NULL)
            {
                root.right = new Node();
            }

            root.maxVal = max(root.maxVal, val);
            update(*root.right, val, position, mid + 1, right);
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
        vector<int> v = {9, 1, 6, 5, 3, 7, 8};
        Node root;
        root.maxVal = 0;

        SegmentTree().build(root, v);
        cout << 1;

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
