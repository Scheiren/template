#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 10, mod = 1e9 + 7;
const long long maxN = 2e5 + 1;

class Solution
{
public:
    int succ(int currPos, int steps)
    {
        if (steps == 1)
            return succesor[0][currPos];

        if (steps == 1 << (int)floor(log2(steps)))
            return succesor[(int)floor(log2(steps))][currPos];

        return succ(succ(currPos, floor(log2(steps))), steps - floor(log2(steps)));
    }
    void solve()
    {
        int n, m;
        cin >> n >> m;

        int graph[n + 1];
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a] = b;
        }

        /*
        9 9
        1 3
        2 5
        3 7
        4 6
        5 2
        6 2
        7 1
        8 6
        9 3
        */

        int steps = 11;

        int t = floor(log2(steps));

        for (int i = 1; i <= n; i++)
        {
            succesor[0][i] = graph[i];
        }
        for (int i = 1; i <= t; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                succesor[i][j] = succesor[i - 1][succesor[i - 1][j]];
            }
        }
        cout << succ(4, steps);

        return;
    }

private:
    int succesor[10][10];
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Solution().solve();

    return 0;
}
