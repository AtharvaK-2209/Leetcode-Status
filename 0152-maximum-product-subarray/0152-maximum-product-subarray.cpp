class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Optimal Approach : where we keep track of previous maximum and minimun bcz neg * neg = postive

        int currentMax = nums[0];
        int currentMin = nums[0];
        int answer = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            int temp = currentMax;
            currentMax = max({
                nums[i], 
                currentMax * nums[i], 
                currentMin * nums[i]
            });

            currentMin = min({
                nums[i], 
                temp * nums[i], 
                currentMin * nums[i]
            });
            
            answer = max(answer,currentMax);
        }
        return answer;
    }
};