class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0; i<nums.size(); i++){
            int required = target - nums[i];
            if(map.count(required)){
                return {map[required], i};
            }
            map[nums[i]] = i;
        }
        return{};
    }
};