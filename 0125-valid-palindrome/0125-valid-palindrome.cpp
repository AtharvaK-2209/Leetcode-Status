class Solution {
public:
    bool isPalindrome(string s) {
        // Brute Force Approach : Use clean string to store only letter and digit then check for palindrome
        // string clean = "";
        // for(char c : s){
        //     if(isalnum(c)) 
        //         clean += tolower(c);
        // }
        // int left = 0, right = clean.size()-1;
        // while(left < right){
        //     if(clean[left] != clean[right]) return false;        
        //     left ++;
        //     right --;
        // }
        // return true;

        // Optimal Approach : Direct 2 pointers in original string :
       int left = 0, right = s.size()-1;
        while(left < right){
            while(left < right && !isalnum(s[left]))
                left++;
            while(left < right && !isalnum(s[right]))
                right--;

            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;


    }
};