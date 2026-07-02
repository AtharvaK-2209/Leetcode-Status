class Solution {
public:
    // bool search(vector<int>& nums, int target) { // Linear Search 
    //     for(int num : nums) {
    //         if(num == target)
    //             return true;
    //     }
    //     return false;
    // }

    int longestConsecutive(vector<int>& nums) {
        // Brute force approach : Time : O(n^2);
        // int longest = 0;
        // for(int num : nums) {
        //     int current = num; 
        //     int length = 1;
        //     while(search(nums, current + 1)) {
        //         current++;
        //         length++;
        //     }
        //     longest = max(longest, length);
        // }
        // return longest;

        // Optimal Approach : HashSet
        unordered_set<int> st (nums.begin(), nums.end());
        
        int longest = 0 ;
        for(int num : st){
            if(!st.count(num - 1)){
                int current = num;
                int length = 1;

                while(st.count(current + 1)){
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};