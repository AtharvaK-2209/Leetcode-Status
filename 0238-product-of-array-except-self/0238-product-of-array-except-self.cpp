class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n,1);
        // Brute Force Approach : Time complexity : O(n^2) give TLE
        // for(int i =0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i == j) continue;
        //         ans[i] *= nums[j]; 
        //     }
        // }

        // Optimal Approach : Prefix Product + Suffix Product approach
        // ans[i] = (Product of all the elements on the LEFT of i) * (Product of all the elements on the RIGHT of i)
        // Path 1 : Store LEFT Products
        int prefix = 1;
        for(int i =0 ; i< n ; i++){
            ans[i] = prefix;
            prefix *= nums[i];
        }      

        // Path 2 : Multiply the RIGHT Products to get final answer
        int suffix = 1;
        for(int i = n-1 ; i >= 0 ; i--){
            ans[i] *= suffix;
            suffix *= nums[i];
        }  

        return ans;
    }
};