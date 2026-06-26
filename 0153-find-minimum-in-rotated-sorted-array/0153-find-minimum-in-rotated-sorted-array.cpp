class Solution {
public:
    int findMin(vector<int>& nums) {
        // Brute Force Approach : checking every element. Time : O(n)
        // int minimum = nums[0];
        // for(int i = 1 ; i < nums.size(); i++){
        //     minimum = min(minimum , nums[i]);
        // }
        // return minimum;

        // Optimal Approach : Time: O(log n) Binary Search 
        int left = 0 , right = nums.size()-1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[right]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
    }
};