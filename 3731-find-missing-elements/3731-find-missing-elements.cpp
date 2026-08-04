class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int mn = nums[0], mx = nums[nums.size()-1];
        for(int num = mn; num <= mx; num++) {
            bool found = false;
            for(int x : nums) {
                if(x == num) {
                    found = true;
                    break;
                }
            }
            if(!found)
                ans.push_back(num);
        }

        return ans;
    }
};