class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minN = INT_MAX, maxN = INT_MIN;
        int minpos = 0, maxpos = 0;
        // Finding max and min position

        for(int i = 0 ; i < n ; i++ ){
            if(minN > nums[i]){
                minN = nums[i];
                minpos = i;
            }
            if(maxN < nums[i]){
                maxN = nums[i];
                maxpos = i;
            }
        }
        int first, second, third;
        // Case 1 : if both elements lie in 1st half to delete from begin
        first = max(minpos, maxpos)+1;
        
        // Case 2 : if elements lie in the 2nd half to delete from the end
        second = n - min(minpos, maxpos);
        
        // Case 2 : if one element lie in first half and another element in 2nd half to delete from both sides 
        third = min(minpos, maxpos)+1 +  n - max(minpos, maxpos) ;
        
        return min({first, second, third});

    }
};