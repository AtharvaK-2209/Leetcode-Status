class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
       int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        int bestPos = -1;
        int bestChar = -1;

        // Find the rightmost position where we can make
        // the permutation strictly greater than target.
        for (int i = 0; i < n; i++) {
            // Try making target[i] larger using remaining characters
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bestPos = i;
                    bestChar = c;
                }
            }

            // To continue matching target, we must have target[i]
            if (cnt[target[i] - 'a'] == 0)
                break;

            cnt[target[i] - 'a']--;
        }

        // No permutation greater than target exists
        if (bestPos == -1)
            return "";

        // Rebuild counts
        cnt.assign(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        string ans = "";

        // Keep prefix equal to target
        for (int i = 0; i < bestPos; i++) {
            ans += target[i];
            cnt[target[i] - 'a']--;
        }

        // Put the smallest possible character greater than target[bestPos]
        for (int c = target[bestPos] - 'a' + 1; c < 26; c++) {
            if (cnt[c] > 0) {
                ans += char('a' + c);
                cnt[c]--;
                break;
            }
        }

        // Fill remaining characters in increasing order
        for (int c = 0; c < 26; c++) {
            while (cnt[c] > 0) {
                ans += char('a' + c);
                cnt[c]--;
            }
        }

        return ans; 
    }
};