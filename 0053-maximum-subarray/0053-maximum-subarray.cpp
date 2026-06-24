class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int win_sum = 0;
        for(int i = 0;i<nums.size();i++){
            win_sum += nums[i];
            max_sum = max(max_sum,win_sum);
            if(win_sum < 0){
                win_sum = 0;
            }
        }
        return max_sum;
    }
};