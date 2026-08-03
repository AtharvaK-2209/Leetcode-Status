class Solution {
public:
    vector<int> dp;
    int solve(vector<int> &stoneValue, int i){
        if( i>= stoneValue.size())
            return 0;
        if(dp[i] != INT_MIN)
            return dp[i];
        
        int take = 0;
        int best = INT_MIN;
        for(int k = 0 ; k < 3 && i+k < stoneValue.size(); k++){
            take += stoneValue[i+k];
            best = max(best, take - solve(stoneValue, i + k + 1));

        }
        return dp[i] = best;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        dp.assign(stoneValue.size(), INT_MIN);
        int diff = solve(stoneValue, 0);
        if(diff > 0 )
            return "Alice";
        if(diff < 0)
            return "Bob";
        
        return "Tie";
    }
};