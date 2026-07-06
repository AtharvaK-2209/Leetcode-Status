class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Brute Force : Generate every possible substring. For each substring, check whether it contains duplicate characters.If not, update the maximum length.

        // int n = s.size();
        // int longest = 0;
        // for(int i = 0; i < n ; i++){
        //     unordered_set<char> st;
        //     for(int j = i; j < n ; j++){
        //         if(st.count(s[j]))
        //             break;
        //         st.insert(s[j]);
        //         longest = max(longest, j-i+1);
        //     }
        // }
        // return longest;

        // Optimal Approach : Sliding Window + HashMap

        unordered_map < char, int> mp;
        int left = 0 , longest = 0;
        for(int right = 0 ; right < s.size(); right++){
            if(mp.count(s[right])){
                left = max(left, mp[s[right]] + 1);
            }
            mp[s[right]] = right;
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};