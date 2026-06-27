class Solution {
public:
    bool isAnagram(string s, string t) {
        // Brute Force : Sorting the array. Time : O(n log n)
        // if(s.length() != t.length()){
        //     return false;
        // }
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // if(s == t ) return true;
        // return false;

        // Optimal : Using Frequency array since only English letters are present in strings. Time : O(n). If the inputs contain Unicode or arbitrary Characters we will think for unordered_map<char, int>


        vector <int> freq(26,0);
        for(char c : s){
            freq[c-'a']++;
        }
        for(char c : t){
            freq[c-'a']--;
        }

        for(int count : freq){
            if(count != 0)
                return false;
        }

        return true;

    }
};