class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        
        // Brute Force Approach : Calculate maxSum for every possible subarray at index i
        // for(int i = 0; i< n; i++){
        //     int currentSum = 0;
        //     for( int j = i ; j < n ;j++){
        //         currentSum += nums[j];

        //         maxSum = max(maxSum, currentSum);
        //     }
        // }

        // Optimal Approach : Kdane's Algorithm
        int currentSum = 0;
        for(int i = 0 ; i < n ; i++){
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);

            if(currentSum < 0) {
                currentSum = 0;
            }

            
        }

        return maxSum;
    }
};