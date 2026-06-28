class Solution {
public:
    bool isPalindrome(string s) {
        // Brute Force Approach : Use clean string to store only letter and digit then check for palindrome
        string clean = "";
        for(char c : s){
            if(isalnum(c)) 
                clean += tolower(c);
        }
        int left = 0, right = clean.size()-1;
        while(left < right){
            if(clean[left] != clean[right]) return false;        
            left ++;
            right --;
        }
        return true;
    }
};