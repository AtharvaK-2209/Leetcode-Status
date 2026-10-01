class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int first = 0, last = nums.size() -1;
        // int mid = first + (last-first)/2;
        // return nums[mid];
        // Optimal Solution  : Moore's Voting Algorithm
        int cnt = 0; 
        int el;
        for(int i = 0 ; i < nums.size(); i++ ) {
            if(cnt == 0 ){
                cnt = 1;
                el = nums[i];
            }
            else if( nums[i] == el) cnt++;
            else cnt--;
        }
        int cnt1;
        for(int i = 0 ;  i < nums.size(); i++ ){
            if(el == nums[i]) 
                cnt1++;
        }
        if(cnt1 > (nums.size() / 2 )){
            return el;
        }
        return -1;
    }
};