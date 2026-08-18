class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size();
        // Sliding window
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;
            // Current window
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }
            // Count each distinct number only once per window
            for (int x : st) {
                count[x]++;
            }
        }
        int ans = -1;
        for (auto &[x, freq] : count) {
            if (freq == 1) {
                ans = max(ans, x);
            }
        }
        return ans;
    }
};