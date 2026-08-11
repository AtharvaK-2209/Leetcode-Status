class Solution {
public:
    int missingInteger(vector<int>& nums) {
        const unordered_set<int> s(nums.begin(), nums.end());
        const int n = nums.size();
        assert(n >= 1 && n <= 50);
        for (int x : s) {
            assert(x >= 1 && x <= 50);
        }
        int t = 0;
        for (int i = 0; i < n && nums[i] - nums[0] == i; t += nums[i++])
        ;
        for (; s.count(t); ++t)
        ;
        return t;
    }
};