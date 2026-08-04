class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int mn = nums[0], mx = nums[nums.size()-1];
        unordered_set<int> st(nums.begin(), nums.end());
        for(int num = mn; num <= mx; num++) {
            if(!st.count(num))
                ans.push_back(num);
        }

        return ans;
    }
};