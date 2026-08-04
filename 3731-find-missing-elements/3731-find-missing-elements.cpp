class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        unordered_set<int> st(nums.begin(), nums.end());
        for(int num = mn; num <= mx; num++) {
            if(!st.count(num))
                ans.push_back(num);
        }

        return ans;
    }
};