class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i : nums){
            freq[i]++;
        }
        int maxfreq = 0 ;
        int ans = nums[0];
        for(auto it : freq){
            if(it.second > maxfreq){
                maxfreq = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};