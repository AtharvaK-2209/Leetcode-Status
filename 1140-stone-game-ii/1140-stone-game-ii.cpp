class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        // Can take everything
        if (2 * M >= n - i)
            return dp[i][M] = suffix[i];

        int ans = 0;

        for (int x = 1; x <= 2 * M; x++) {
            int nextM = max(M, x);

            ans = max(ans,
                      suffix[i] -
                      solve(i + x, nextM));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};