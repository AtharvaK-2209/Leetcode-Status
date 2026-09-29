class Solution {
public:
    vector<int> reverseArray(vector<int> &nums, int left, int right){
        while(left < right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
        return nums;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        // int temp[k];
        // for (int i = n-k; i < n ; i++){
        //     temp[i - (n-k)] = nums[i];
        // }        
        // for(int i = n-k-1; i >= 0; i--){
        //     nums[i+k] = nums[i];
        // }
        // for(int i = 0 ; i < k ; i++){
        //     nums[i] = temp[i];
        // }
        // optimal approach : changing array without creating any extra variable/array
        reverseArray(nums, 0, n-1);
        reverseArray(nums, 0, k-1);
        reverseArray(nums, k, n-1);

    }
};