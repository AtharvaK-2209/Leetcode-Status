class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first = 0, last = nums.size() -1;
        int mid = first + (last-first)/2;
        return nums[mid];
    }
};