class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        auto makePalindrome = [&](string left) {
            string res = left;

            if (n % 2)
                res += mid;

            reverse(left.begin(), left.end());
            res += left;

            return res;
        };

        vector<int> temp = half;
        string left = "";
        bool possible = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (temp[x] == 0) {
                possible = false;
                break;
            }

            temp[x]--;
            left += target[i];
        }

        if (possible) {
            string candidate = makePalindrome(left);

            if (candidate > target)
                return candidate;
        }
        half.assign(26, 0);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int bestPos = -1;
        int bestChar = -1;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';
            for (int c = x + 1; c < 26; c++) {
                if (half[c] > 0) {
                    bestPos = i;
                    bestChar = c;
                    break;
                }
            }

            if (half[x] == 0)
                break;

            half[x]--;
        }

        if (bestPos == -1)
            return "";

        half.assign(26, 0);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        string ansLeft = "";

        for (int i = 0; i < bestPos; i++) {
            ansLeft += target[i];
            half[target[i] - 'a']--;
        }

        ansLeft += char('a' + bestChar);
        half[bestChar]--;

        for (int c = 0; c < 26; c++) {
            while (half[c] > 0) {
                ansLeft += char('a' + c);
                half[c]--;
            }
        }

        return makePalindrome(ansLeft);
    }
};